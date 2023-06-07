#include <string>
#include <vector>
#include <map>
#include<iostream>
using namespace std;
/*
 A - AA - AAA - AAAA - AAAAA
                     - AAAAE
                     - AAAAI
                     - AAAAO
                     - AAAAU
              - AAAE 
              - AAAI
              - AAAO
              - AAAU
*/
const char words[5] = {'A','E','I','O','U'};
int cnt = 1;
void dfs(map<string,int>& dict,string sample){
        if(sample.size() >= 5) return;    
    
        for(int i=0; i<5; ++i){
            string temp = sample + words[i];
            if(dict[temp]) continue;
            dict[temp] = cnt++;
            dfs(dict, temp);
        }
    
    
}


int solution(string word) {
    int answer = 0;
    map<string,int> dict;
    dfs(dict,"");
    //cout << dict["A"] << endl;
    answer = dict[word];
    return answer;
}