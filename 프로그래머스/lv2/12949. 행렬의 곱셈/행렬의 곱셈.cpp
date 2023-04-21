#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(),vector<int>(arr2[0].size(),0));
    
    /*
        [1,4]
        [3,2] * [3,3] = (ax+bu, ay+bk)
                [3,3]   (a2x+bu, )
        [4,1]
    */
    for(int i=0 ;i<arr1.size(); ++i){
        for(int j=0; j<arr2[0].size(); ++j){
            int value = 0;
            for(int k=0; k<arr1[0].size(); ++k){
                value += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = value;
        }
    }
    
    // 2 x 3  * 3 x 2 = ;
    return answer;
}