#include <vector>
#include <string>
#include<algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            // 접두어가 있는 경우
            return false;
        }
    }
    return true;

}

