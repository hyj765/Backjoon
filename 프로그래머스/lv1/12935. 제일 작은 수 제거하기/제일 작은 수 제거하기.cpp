#include <string>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }

    int s =  *min_element(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i) {
        if (s == arr[i]) {
            arr.erase(arr.begin() + i);
            break;
        }
    }
    
    answer = arr;

    return answer;
}
