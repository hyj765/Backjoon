#include <iostream>

using namespace std;

/*
    
    n은 8 a 4 b 4
    
    
     2   2   2   2
    1 2 3 4 5 6 7 8
    
    
    1 1 2 2 3 3 4 4
     1   1   2   2
     
*/

int pick(int a){
    if(a == 1) return 1;
    if(a % 2 != 0){
        a = (a / 2) + 1;
    }else{
        a = (a / 2);
    }   
    
    return a;
}

int solution(int n, int a, int b)
{
    int answer = 0;
    while(1){
        //printf("%d %d\n", a, b);
        a = pick(a);
        b = pick(b);
        if(a == b){
            answer++;
            break;
        }
        answer++;
    }
    //printf("answer: %d",answer);
    return answer;
}