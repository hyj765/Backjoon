#include <string>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;

// 두글자씩 끊어 다중집합원소로 만든다.
// 이 때 글자로 된 쌍만 유호하고 공백이나 숫자, 특수문자가 들어있는 경우 그 쌍을 버린다.

bool isCharacter(char ch){
    if(ch >= 65 && ch <= 90){
        return true;
        }
    return false;
}

map<string,int> extract_(const string& s){
    map<string,int> rStr;
    for(int i=0; i<s.size()-1; ++i){
        char ch1 = s[i];
        char ch2 = s[i+1];
        if(isCharacter(ch1) && isCharacter(ch2)){
            string temp = "";
            temp += ch1;
            temp += ch2;
            rStr[temp] += 1;
        }
    }
    return rStr;
}

void upperstring(string& str){
    for(int i=0; i<str.size(); ++i){
        str[i] = toupper(str[i]);
    }
}

int calculate_intersection(map<string,int> m1, map<string,int> m2){
    int v = 0;
    for(pair<string,int> temp:m1){
        string key = temp.first;
        if(m2[key] > 0){
            //cout << key << endl;
            if(m1[key] == m2[key]) v +=m1[key];
            else {
                v += min(m1[key],m2[key]);
            }
        }
    }
    
    return v;
}
// 교집합 추출함수.

int calculate_union(map<string,int> m1, map<string,int> m2){
    int v = 0;
    set<string> keys;
    for(pair<string,int> s:m1){
        keys.insert(s.first);
    }
    for(pair<string,int> s:m2){
        keys.insert(s.first);
    }
    
    for(string key:keys){
        if(m1[key] == m2[key]) v+= m1[key];
        else v+= max(m1[key],m2[key]);
    }
    
    return v;
}
// 합집합 추출함수.
int solution(string str1, string str2) {
   int answer = 0;
    upperstring(str1);
    upperstring(str2);
    map<string,int> estr1 = extract_(str1);
    map<string,int> estr2 = extract_(str2);
    int inter_v =calculate_intersection(estr1,estr2);
    int union_v =calculate_union(estr1,estr2);
    if(inter_v == 0 && union_v == 0) return 65536;
    answer = ((float)inter_v/union_v)*65536;
    return answer;
}