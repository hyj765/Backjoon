#include <string>
#include <vector>

using namespace std;
bool n[20];
int cnt;
void solv(int depth,int len,const vector<int> &numbers,int target){
    if(depth == len){
        int v = 0;
        for(int i=0; i<len; ++i){
            if(n[i]) v+=numbers[i];
            else v-=numbers[i];
        }
        if(v == target) cnt++;
        return;
    }
    n[depth] = true;
    solv(depth+1,len,numbers,target);
    n[depth] = false;
    solv(depth+1,len,numbers,target);
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    solv(0,numbers.size(),numbers,target);
    answer = cnt;
    return answer;
}