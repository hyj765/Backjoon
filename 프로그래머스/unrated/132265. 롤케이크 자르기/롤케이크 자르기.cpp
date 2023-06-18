#include <string>
#include <vector>
#include<iostream>
#include<set>
using namespace std;
int larrcnt[10001];
int rarrcnt[10001];
int solution(vector<int> topping) {
    int answer = 0;
    set<int> lkeys;
    set<int> rkeys;
    
    for(int i=0; i<topping.size(); ++i){
        rarrcnt[topping[i]]++;
        rkeys.insert(topping[i]);    
    }
    for(int i=0; i<topping.size(); ++i){
        if(--rarrcnt[topping[i]]== 0) {
            rkeys.erase(topping[i]);    
        }
        lkeys.insert(topping[i]);
        if(lkeys.size() == rkeys.size()){
          //cout << i << " "<< rkeys.size() << " " << lkeys.size() << endl;  
          answer++;
        } 
    }

    return answer;
}