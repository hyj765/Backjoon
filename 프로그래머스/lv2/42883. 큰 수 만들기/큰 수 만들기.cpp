#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


string solution(string number, int k) {
	string answer = "";
    int index = -1;
    for(int i=0; i<number.size()-k; i++){
        char maxVal = ' ';
        for(int j=index+1; j<=k+i; j++){
            if(maxVal < number[j]){
                maxVal = number[j];
                index = j;
            }
        }
        answer += maxVal;
    }
	return answer;
}