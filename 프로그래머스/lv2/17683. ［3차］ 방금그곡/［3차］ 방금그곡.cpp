#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
/*

   1. 조건이 일치하는 음악이 다수의 경우 라디오 /재생시간이 제일 긴/ 음악 제목 반환.
   2. 재생시간도 같을 시 먼저 입력된 음악 제목 반환.
   3. 일치하는 음악이 없을 경우 none 반환.
   
*/

bool compare(pair<string,pair<int,int>> m1, pair<string,pair<int,int>> m2){
    if(m1.second.first == m2.second.first){
        return m1.second.second < m2.second.second;
    }
    return m1.second > m2.second;
}

vector<string> split(const string& str, const char& delimeter){
    
    string buffer="";
    vector<string> strarray;
    for(int i=0; i<str.size(); ++i){
        if(delimeter == str[i]){
            strarray.push_back(buffer);
            buffer = "";
            continue;
        }
        buffer+=str[i];
    }
    strarray.push_back(buffer);
    
    return strarray; 
}

string convertMelody(string melody){
    string convert = "";
    for(int i=0; i<melody.size(); ++i){
        string temp = "";
        temp += melody[i];
        if(i+1 != melody.size()){
            if(melody[i+1] == '#'){
                temp += '#';
                i++;
            }
        }
        if(temp == "C#") temp = 'c';
        else if(temp == "D#") temp = 'd';
        else if(temp == "F#") temp = 'f';
        else if(temp == "G#") temp = 'g';
        else if(temp == "A#") temp = 'a';
        convert += temp;
    }
    return convert;
}

bool musicCheck(string melody,int playTime,string targetMelody){
    string temp = "";
    string convert=convertMelody(melody);
    /*
        if melody.size() < playtime then temp += melody[i%melody.size()]; 
        완성된 temp 문자열에서 find를 써서 찾아보기
        완전탐색으로 하나씩 체크해보면서 찾기인데 find도 거의 mn임
    */
    for(int i=0; i<playTime; ++i){
        temp += convert[i%convert.size()];
    }  
    
    if(temp.find(targetMelody) == string::npos){
        return false;
    }
    
    return true;
}

int getPlayTime(string start,string end){
    string endHour=end.substr(0,2);
    string endMinute = end.substr(3,2);
    string startHour=start.substr(0,2);
    string startMinute = start.substr(3,2);
    
    int endTime = stoi(endHour.c_str())*60 + stoi(endMinute.c_str());
    int startTime = stoi(startHour.c_str())*60 + stoi(startMinute.c_str());
    
    return endTime - startTime; 
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    string convertstr = convertMelody(m);
    
    vector<pair<string,pair<int,int>>> musicList;
    int cnt = 0;
    for(string musicinfo:musicinfos){
        vector<string> info = split(musicinfo,',');
        string start = info[0];
        string end = info[1];
        string name = info[2];
        string melody = info[3];
        int playTime = getPlayTime(start,end);
        if(musicCheck(melody,playTime,convertstr)){
            musicList.push_back({name,{playTime,cnt++}});
        }
    }
    
    if(musicList.size() == 0) return "(None)";
    sort(musicList.begin(),musicList.end(),compare);
    
    answer = musicList[0].first;
    
    return answer;
}