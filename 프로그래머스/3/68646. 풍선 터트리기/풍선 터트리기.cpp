#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 2;
    vector<int> left_min(1000000);
    vector<int> right_min(1000000);

    left_min[0] = a[0];
    for (int i = 1; i < a.size(); ++i) left_min[i] = min(left_min[i - 1], a[i]);

    right_min[a.size() - 1] = a[a.size() - 1];
    for (int i = a.size() -2; i >= 0; --i) right_min[i] = min(right_min[i+1], a[i]);


    for (int i = 1; i < a.size() - 1; ++i) {
        if (a[i] < left_min[i - 1] || a[i] < right_min[i + 1]) {
            answer++;
        }
    }

    /*
      -16 27 65 -2 58 -92 -71 -68 -61 -33
      -33 -16 -92 -71 -68 -61

    */

    return answer;
}