#include <string>
#include <vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

set<string> comb;
vector<string> con(8);
vector<bool>visit(8,false);
void simulate(const vector<string>& user_id, const vector<string>& banned_id, int depth){
    if(depth == banned_id.size()){
        string temp = "";
        vector<string> tcon;
        for(int i=0; i<banned_id.size(); ++i){
            tcon.push_back(con[i]);
        }
        sort(tcon.begin(),tcon.begin()+depth);
        for(string v:tcon) temp += v;
        comb.insert(temp);
        return;
    }
    
    for(int i=0; i<user_id.size(); ++i){
        if(user_id[i].size() != banned_id[depth].size()) continue;
        if(visit[i]) continue;
        bool flag = true;
        for(int j=0; j<user_id[i].size(); ++j){
            if(banned_id[depth][j] == '*') continue;
            if(user_id[i][j] != banned_id[depth][j]){
                flag=false;    
                break;
            }
        }
       if(!flag) continue;
       visit[i] = true;
       con[depth] = user_id[i];
       simulate(user_id,banned_id,depth+1);
       con[depth] = "";
        visit[i] = false;
    }
    
    
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    simulate(user_id,banned_id,0);
    //for(string v: comb) cout << v << endl;
    answer = comb.size();
    return answer;
}