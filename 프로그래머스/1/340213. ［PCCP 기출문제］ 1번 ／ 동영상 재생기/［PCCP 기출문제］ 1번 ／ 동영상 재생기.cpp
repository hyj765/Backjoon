#include <string>
#include<iostream>
#include <vector>

using namespace std;


int getTime(string str)
{
   string hour = str.substr(0,2);
   string minute = str.substr(3,2);
    
   int ihour =stoi(hour);
   int imin =stoi(minute);

    return (ihour* 60) + (imin);
}

bool isInsideOp(int op_start,int op_end, int time)
{
    if(op_start <= time && time <= op_end)
    {
        return true;
    }
    
    return false;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int iop_start = getTime(op_start);
    int iop_end = getTime(op_end);
    int ipos = getTime(pos);
    int ivideo_len = getTime(video_len);
    for(string command:commands)
    {
        if(isInsideOp(iop_start,iop_end,ipos))
        {
            ipos = iop_end;
        }
        
        if("next" == command)
        {
            if(ipos + 10 >= ivideo_len)
            {
                ipos = ivideo_len;
            }else {
                ipos += 10;
            }
        }else if("prev" == command)
        {
            if(ipos < 10)
            {
                ipos = 0;
            }else {
                ipos -= 10;
            }
        }
    }
    
    if(isInsideOp(iop_start,iop_end,ipos))
        {
            ipos = iop_end;
        }
    
    int h = ipos / 60;
    int m = ipos % 60;
    if(h <= 10)
    {
        answer += '0';
    }
    answer += to_string(h);
    answer += ':';
    if(m <= 10)
    {
        answer += '0';
    }
    answer += to_string(m);
    cout << answer << " ";
    
    return answer;
}