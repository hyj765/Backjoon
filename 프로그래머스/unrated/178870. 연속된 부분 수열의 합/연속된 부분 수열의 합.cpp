#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,-1);
    int siz = sequence.size();
    int len = INT32_MAX;
    int left  =0;
    int right =0;
    int cur = 0;
    while(left <= right && right -1 < siz){
        if(cur < k){
            cur += sequence[right];
            right++;
        }else{
            if(cur == k){
                if( len > right - left ){
                    len = right - left;
                    answer[0] = left;
                    answer[1] = right -1;
                }else if(len == right - left){
                    if(answer[0] > left ){
                        answer[0] = left;
                        answer[1] = right -1;
                    }
                }
            }
            cur -= sequence[left];
            left++;
        }    
    }
    
    return answer;
}