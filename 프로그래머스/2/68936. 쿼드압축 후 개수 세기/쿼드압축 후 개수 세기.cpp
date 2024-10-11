#include <string>
#include <vector>

using namespace std;

pair<int,int> Compression(const vector<vector<int>>& arr, int size, int startx, int starty )
{
    int zero = 0;
    int one = 0;
    if(size == 1)
    {
        if(arr[startx][starty] == 1)
        {
            one++;
        }else{
            zero++;
        }
            
        return {zero,one};
    }
    
    auto s1 = Compression(arr,size/2,startx, starty);
    zero += s1.first;
    one += s1.second;
    auto s2 = Compression(arr,size/2,startx + size/2, starty);
    zero += s2.first;
    one += s2.second;
    auto s3 = Compression(arr,size/2,startx, starty+ size/2);
    zero += s3.first;
    one += s3.second;
    auto s4 = Compression(arr,size/2,startx + size/2, starty + size/2);
    zero += s4.first;
    one += s4.second;
    
    if(zero == 4 && one == 0)
    {
        zero = 1;
        return {zero,one};
    }
    else if(zero == 0 && one == 4)
    {
        one = 1;
        return {zero,one};
    }
    
    return {zero,one};
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    auto value = Compression(arr,n,0,0);
    
    answer.push_back(value.first);
    answer.push_back(value.second);
    
    return answer;
}