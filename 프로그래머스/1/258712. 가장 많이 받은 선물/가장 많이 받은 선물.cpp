#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

/*
    선물 기록이 있음.
    -> 선물을 많이 준 사람이 선물을 다음 달에 받음
    -> 근데 이게 하나만 줌 그 차액이 아니라
    
    제약사항
    1. 같거나 기록이 없으면 선물 지수에 따라 선물지수가 큰 사람이 낮은 사람에게 선물 하나 받음
    
    
    
    선물지수 : 이번 달 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값
    send - receive  = gist score
    
    종인 == 성인 [0][0]  -> 인호한테 주거나  3 - 2 = 1 == 0
    
    선물 지수가 == 안 줌.
    
    friends = 이름
    gifts = 선물기록
    
    결과
    당신은 선물을 가장 많이 받을 친구가 받을 선물의 수를 알고 싶습니다.
*/
vector<string> split(string str, char delimeter)
{
    vector<string> arr;
    
    string buffer;
    stringstream ss(str);
    
    while(getline(ss,buffer,delimeter))
    {
        arr.push_back(buffer);    
    }
    
    return arr;
}


int dp[50][50];

int getIndex(string name, const vector<string>& friends)
{
    int index = 0;
    for(int i=0; i<friends.size(); ++i)
    {
        if(name == friends[i])
        {
            return i;
        }
    }
    return -1;
}



int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    /*
    muzi = 0;
    ryan = 1;
    
    */
    
    int n = friends.size();
    vector<int> giftscore(n,0);
    for(int i=0; i<gifts.size(); ++i)
    {
        vector<string> splitedstring =split(gifts[i],' ');
        
        string sender = splitedstring[0]; 
        string receiver = splitedstring[1];
        int sindex = getIndex(sender, friends);
        int rindex = getIndex(receiver, friends);
       // cout << sindex << " " << rindex << endl;
        dp[sindex][rindex]++;
        
        giftscore[sindex]++;
        giftscore[rindex]--;
        
    }
    
    
    
    for(int i=0; i<n; ++i)
    {
        int score = 0; 
        for(int j =0; j<n; ++j)
        {
            if( i == j ) continue;
            if(dp[i][j] > dp[j][i]) 
            {
                score++;
            }
            else if(dp[i][j] == dp[j][i])
            {
                if( giftscore[i] > giftscore[j] )
                {
                  //  cout << i << " " << j << endl;
                    score++;
                }
            }
        }
        if(answer < score) answer = score;
    }
    

    
    
    return answer;
}