#include <iostream>
#include<stdlib.h>
#include <string>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;
bool compare(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> v;
    vector<vector<int>> rmap;
    string temp = "";
    bool trigger = false;
    for(int i=1; i<s.size()-1; ++i){
        //printf("%d: %d \n", i,trigger);
        if(s[i] == '{'){
            trigger = true;
        }else if(s[i] == '}'){
            if(temp != "") v.push_back(atoi(temp.c_str()));
            if(v.size() != 0) rmap.push_back(v);
            trigger = false;
            temp = "";
            v.clear();
        }else if(s[i] >= 48 && s[i] <= 57){
            temp += s[i];
        }else if(s[i] == ',' && trigger){
            int value = atoi(temp.c_str());
            v.push_back(value);
            temp = "";
        }
    }
    sort(rmap.begin(),rmap.end(),compare);
    int tusiz = rmap[rmap.size() -1].size();
    map<int,bool> st;
    for(int i=0; i<tusiz; ++i){
        for(int j=0; j<rmap[i].size(); ++j){
            if(!st[rmap[i][j]]){
                st[rmap[i][j]] = true;
                answer.push_back(rmap[i][j]);
                break;
            } 
        }
        
        
    }
    return answer;  
}
    