#include <string>
#include <vector>
#include<iostream>
#include <stack>
using namespace std;

bool check(const string& s) {

    stack<char> buffer;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            buffer.push(s[i]);
        }
        else {
            if (buffer.empty()) return false;
            char top = buffer.top();
            buffer.pop();
            if (s[i] == ')') {
                if (top != '(') return false;
                
            }
            else if (s[i] == ']') {
                if (top != '[') return false;
                
            }
            else {
                if (top != '{') return false;                
            }

        }
    }
    if (!buffer.empty()) return false;

    return true;
}

void string_location(string& s) {
    char temp = s[0];
    for (int i = 0; i < s.size() - 1; ++i) {
        s[i] = s[i + 1];
    }
    s[s.size() - 1] = temp;
}

int solution(string s) {
    int answer = 0;
    int cnt = 0;
    while (cnt <= s.size()-1) {
        if (check(s)) {
            answer++;
        }
        string_location(s);
        cnt++;
    }
    return answer;
}
