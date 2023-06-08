#include <string>
#include <vector>
#include<iostream>
#include <map>
using namespace std;

bool isUse(const string& pskill,map<char,int> property){
    int step = 1;
    for(int i=0; i<pskill.size(); ++i){
        if(property[pskill[i]] > 0){
            if(property[pskill[i]] > step){
                return false;
            }else{
                step++;
            }
        }
    }
    
    return true;
}

void initialize(map<char,int>& property,const string& skill){
    for(int i=0; i<skill.size(); ++i){
        property[skill[i]] = i+1;
    }
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> property;
    initialize(property,skill);
    for(string tree:skill_trees){
        if(isUse(tree,property)){
            answer++;
            cout << tree << endl;
        }
    }
    
    return answer;
}