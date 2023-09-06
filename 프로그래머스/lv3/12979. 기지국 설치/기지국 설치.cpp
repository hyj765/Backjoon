#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

// n이 2억개 -> 순조부 완탐 불가



int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    if(stations.size() == 0){
        if(n <= (w*2+1)){
            return 1;
        }
        answer = ceil((float)n/(w*2 +1));
        return answer;
    }
    
    // 11 float n / (w*2 +1)
    
    int start = 1;
    for(int station:stations){
        int end = station - w;
        if(end > start){
            //cout << start << " " << end << " ";
            int partsize = end - start;
            answer += ceil((float)partsize/(w*2+1));
        }
        start = station + w+1;
    }
    
    if(start < n){
        int partsize =n - start;
        answer += ceil((float)partsize/(w*2+1));
    }else if(start == n){
        answer += 1;
    }
    
    /*
       13
       
       3 7 11
       1 2 3 4 5 6 7 8 9 10 11 12 13
         1 1 1   1 1 1    1  1 1
        
        empty location = {{1 ,2 } {6,7,8,9}};
                             1       station = 4; w = 1        ebx = station/(w*2 + 1)  0 != station%(w*2+1) 
                             +1
    */
    
    
    return answer;
}