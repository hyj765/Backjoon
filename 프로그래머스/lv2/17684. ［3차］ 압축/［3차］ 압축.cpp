#include <string>
#include <vector>
#include<map>
using namespace std;
/*

    1. a ~ z map으로 초기화 - cnt 필요함.
    2. 
    글자수대로 answer.push_back()
    {   
        if(cur + 1 < length){
            int step = 1;
            while(dict[cur] != 0 && cur + step < length){
                cur += cur+1;
                step++;
            }
            dict[cur] = ++cnt;
        }else then push dict[cur];
        
    }
*/
vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> dict;
    char delimeter = 65;
    int cnt = 1;
    for(int i=0; i<26; ++i) {
        string s = string(1,delimeter+i);
        dict[s] = cnt++;
    }
    for(int i=0; i<msg.size(); ++i){
        if(i+1 < msg.size()){
            string cur="";
            cur += msg[i];
            int step = 1;
            while(dict[cur] != 0){
                cur += msg[i+step];
                step++;
            }
            i += step -2;
            if(dict[cur]) answer.push_back(dict[cur]);
            else {
                dict[cur] = cnt++;
                cur.pop_back();
                answer.push_back(dict[cur]);
            }
        }else{
            answer.push_back(dict[string(1,msg[i])]);
        }
    }
    return answer;
}