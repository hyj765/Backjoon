#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    // lim if(n1 < n2) d ....
    int len = elements.size();
    set<int> s;
    for(int i=0; i<elements.size(); ++i){
        int left=0;
        int temp = 0;
        while(left < len){
            int x = (i+left)%len;         
            left++;
            temp += elements[x];
            s.insert(temp);
        }
    }
    answer = s.size();
    
    return answer;
}