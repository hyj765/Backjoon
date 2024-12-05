#include <string>
#include <vector>

using namespace std;
/*
    n1 % 2 == 0
    return n1 + 1;
    
*/

long long getAnswer(long long number)
{
    if(number % 2 == 0)
    {
        return number+1;
    }else
    {
        long long c = 1;
        while(true)
        {
            if((number & c) == 0) break;
            c *= 2;
        }
        
        
        return (number + ( c / 2 ));
    }
}


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0; i<numbers.size(); ++i)
    {
        answer.push_back(getAnswer(numbers[i]));
    }
    
    return answer;
}