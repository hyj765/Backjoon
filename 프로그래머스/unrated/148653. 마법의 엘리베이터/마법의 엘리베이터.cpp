#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    
    int base = 10;
    int multbase = 1;
    while(storey > 0){
        int extract = storey % base;
        //25555
        if(extract > 5*multbase ){
            int plus = base - extract;
            storey += plus;
            answer += (plus / multbase);
        }else if(extract < 5* multbase){
            storey -= (extract);
            answer += (extract/multbase);   
        }else{    
            if((storey % (base *10)) >= ((5*multbase)*10)){
                storey += extract;
                answer += (extract / multbase);
            }else{
                storey -= extract;
                answer += (extract/multbase);
            }
            
        }
        
        base *= 10;
        multbase *=10;
    }
    
    
    return answer;
}