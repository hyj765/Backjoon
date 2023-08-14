#include <string>
#include <vector>

using namespace std;

int timetable[1440];

int convert(string time){
    int hour = atoi(time.substr(0,2).c_str());
    int minute = atoi(time.substr(3,2).c_str());
    return (hour *60)  + minute; 
}

vector<pair<int,int>> convertTI(vector<vector<string>> bookt){
    vector<pair<int,int>> r;
    for(vector<string> book_time:bookt){
        int start= convert(book_time[0]);
        
        int end = convert(book_time[1]) + 9;
        if(end > 1439) end -= 9;
        r.push_back({start,end});
    }
    
    return r;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> converted=convertTI(book_time);
    
    for(pair<int,int> t:converted){
        for(int i = t.first; i<= t.second; ++i){
            timetable[i]++;   
        }
    }
    
    for(int i =0; i<1440; ++i){
        answer = answer < timetable[i] ? timetable[i] : answer; 
    }
    
    return answer;
}