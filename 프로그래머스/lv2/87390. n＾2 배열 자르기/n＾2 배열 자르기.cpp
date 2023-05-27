#include <string>
#include <vector>

using namespace std;
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    // 2 /n == 0
    // 2 %n == 2
    // 5 /n == 1
    // 5 %n == 2
    // i = 1  i <= 2;
    // 
    int x;
    int y;
    int r;
    for(long long i=left; i<right+1; ++i){
        x = i/n;
        y = i%n;
        answer.push_back(x > y ? x+1 : y+1);
    }
    return answer;
}