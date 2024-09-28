#include <iostream>
#include <string>
using namespace std;

/*

    
    cdeaba
*/

int solution(string s)
{
    int answer = 1;
    for(int i=0; i<s.size(); ++i)
    {
        int index = i;
        int right = i + 1;
        
        while(index >= 0 && right < s.size())
        {
            
            if(s[index] != s[right])
            {
                break;
            }

            index --;
            right ++;
        }
        int value = right - index - 1;
        answer = max(value,answer);
        
        index = i;
        right = i;
        while(index >= 0 && right < s.size())
        {
            if(s[index] != s[right])
            {
                break;
            }
            
            index--;
            right++;
        }
        value = right - index - 1;
        answer = max(value,answer);
    }
    
    
  
    return answer;
}