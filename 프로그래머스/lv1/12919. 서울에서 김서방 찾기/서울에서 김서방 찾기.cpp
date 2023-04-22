#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int i = 0;
    for(string s:seoul){
        if(s == "Kim") {
            break;
        }
        i++;
    }
    answer+= "김서방은 ";
    answer+= to_string(i);
    answer+= "에 있다";
    return answer;
}