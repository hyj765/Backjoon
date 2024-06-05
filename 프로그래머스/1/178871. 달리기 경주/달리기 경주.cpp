#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;


string ss[50001];

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> location;
    for(int i=0; i<players.size(); ++i) 
    {
        ss[i] = players[i];
        location[players[i]] = i; 
    }
    
    for(int i=0; i<callings.size(); ++i)
    {
        int lc = location[callings[i]];
        string competor = ss[lc-1];
        ss[lc] = competor;
        ss[lc-1] = callings[i];
        location[competor] = lc;
        location[callings[i]] = lc-1;
        
        //cout << competor << " " << callings[i] << endl;
    }
    
    for(int i=0; i<players.size(); ++i)
    {
        answer.push_back(ss[i]);
    }
    
    
    return answer;
}