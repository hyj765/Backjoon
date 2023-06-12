#include <string>
#include <vector>
#include<cctype>
#include<iostream>
#include<algorithm>
using namespace std;

/*
    1. 사전순 정렬 대소문자 구분안함.
    2. 숫자가 작을 수록 정렬
    3. head와 number가 같을 경우 입력에 주어진 순서 유지
*/

vector<string> split(string s){
    vector<string> rstr;
    string head="";
    string number="";
    bool nflag = false;
    for(int i=0; i<s.size(); ++i){
        if(!nflag && isdigit(s[i])) nflag = true;
        if(!nflag) head.push_back(toupper(s[i]));
        else if(nflag && isdigit(s[i])) number.push_back(s[i]);
        else break;
    }
    rstr.push_back(head);
    rstr.push_back(number);
    return rstr;
}


bool compare(string s1, string s2){
    vector<string> splited_s1;
    vector<string> splited_s2;
    splited_s1 =split(s1);
    splited_s2 = split(s2);
    if(splited_s1[0] == splited_s2[0]){
        int n1 = atoi(splited_s1[1].c_str());
        int n2 = atoi(splited_s2[1].c_str());
        return n1 < n2;
    }
    
    return splited_s1[0] < splited_s2[0];
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    stable_sort(files.begin(),files.end(),compare);
    answer = files;
    return answer;
}