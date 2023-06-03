#include <string>
#include <vector>
#include <sstream>
#include<map>
#include<set>
using namespace std;

vector<string> split(const string &s){
    string temp;
    vector<string> answer;
    stringstream ss(s);
    while(getline(ss,temp,' ')){
        answer.push_back(temp);
    }
    
    return answer;
}

int convertTime(const string &s){
    string hour = s.substr(0,2);
    string minute = s.substr(3,2);
    int h = atoi(hour.c_str()) * 60;
    int m = atoi(minute.c_str());
    return h+ m; 
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int,int> members; 
    map<int,int> Mfee;
    map<int,bool> check;
    set<int,less<int>> ids;
    for(string record:records){
        vector<string> split_str=split(record);
        int id = atoi(split_str[1].c_str());
        ids.insert(id);
        int time = convertTime(split_str[0]);
        //printf("%d\n", time);
        if(split_str[2] == "IN") {
            members[id] = time;
            check[id] = true;   
        }
        else  {
            Mfee[id] += time - members[id];
            check[id] = false;
        }
        
    }
                                              
    for(const int& val:ids){
       
        int fee = Mfee[val];
        if(check[val]){
           fee +=convertTime("23:59") - members[val];
        }
        
        
        if(fee > fees[0]){
           int end = fees[1];
           end += ((fee - fees[0])/fees[2])*fees[3];
           if((fee - fees[0])%fees[2] != 0) end += fees[3];
           answer.push_back(end);
        }else {
            answer.push_back(fees[1]);
        }
    }                
    
    return answer;
}