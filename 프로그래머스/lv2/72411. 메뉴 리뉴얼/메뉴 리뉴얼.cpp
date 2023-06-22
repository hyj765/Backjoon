#include <string>
#include <vector>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
/*
최소 2명 이상의 손님으로부터 주문된 단품메뉴 조합에 대해서만 코스요리 메뉴 후보에 포함하기로 했습니다.
각 손님들이 주문할 때 가장 많이 함께 주문한 단품메뉴들을 코스요리 메뉴로 구성하기로 했습니다.
orders 2 ~ 20;
각 원소값은 2 ~ 10 이하;
course 1~ 10 범위
*/
bool menusize[11];
int cnt[11];
void subset(string s,const string& order,set<string>& list,int depth){
    
    if(s.size() > 1 && menusize[s.size()]){
        sort(s.begin(),s.end());
        list.insert(s);
    }
    if(depth == order.size()) return;
    subset(s,order,list,depth+1);
    subset(s+order[depth],order,list,depth+1);
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string,int> listcnt;
    for(int len:course) menusize[len] = true;
    for(string order:orders){
        set<string> list;
        subset("",order,list,0);
        for(string li:list){
            listcnt[li] += 1;
        }
    }
    for(pair<string,int> v:listcnt){
        if(v.second >= 2) cnt[v.first.size()] = max(v.second,cnt[v.first.size()]);
        //cout << v.first << " " << v.second << endl;
    }
    for(pair<string,int> v:listcnt){
        int len = v.first.size();
        if(cnt[len] == v.second) answer.push_back(v.first);
    }
    
    
    return answer;
}