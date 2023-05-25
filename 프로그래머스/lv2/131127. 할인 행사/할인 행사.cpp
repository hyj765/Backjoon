#include <string>
#include <vector>
#include <map>
using namespace std;

bool check(vector<string> want,map<string,int> checklist, map<string,int> curlist)
{
        for(string goods:want){
            if(curlist[goods] < checklist[goods]) return false;
        }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> checklist;
    for(int i=0; i<want.size(); ++i){
        checklist[want[i]] = number[i];
    }
    map<string,int> temp;
    for(int i=0; i<10; ++i){
        temp[discount[i]] +=1;
    }
    if(check(want,checklist,temp)) answer++;
    
    for(int i=10; i<discount.size(); ++i){
        temp[discount[i-10]] -=1;
        temp[discount[i]] +=1;
        if(check(want,checklist,temp)){
            answer++;
        }
    }
    /*
            
    
    
    */
    
    
    
    return answer;
}