#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> cases;


void backtracking(int remain, int idx, vector<int> order) {

	if (remain <= 0) {
		cases.push_back(order);
		return;
	}

	for (int i = idx; i < order.size(); ++i) {
		order[i] ++;
		backtracking(remain - 1, i, order);
		order[i]--;
	}
}

int simulate(vector<int> order, vector<vector<int>> reqs){
    priority_queue<int,vector<int>,greater<int>> pq[order.size()];
    int answer =0;
    
    
    for(int i = 1; i < order.size(); i++){
        for(int j = 0; j < order[i]; j++) pq[i].push(0);
    }
    
    
    for(int i=0; i<reqs.size(); ++i){
        int start = reqs[i][0];
        int end = reqs[i][1];
        int type = reqs[i][2];
        
        int top = pq[type].top();
        pq[type].pop();
        
        if(top < start){
            pq[type].push((start+end));
        }else if(top == start){
            pq[type].push((top + end));
        }else{
            answer += top - start;
            pq[type].push((top + end));   
        }
    }
    
    
    return answer;
}



int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = INT32_MAX;
    
    vector<int> mentor(k+1,1);
    
    backtracking(n-k,1,mentor);
    
    for(vector<int> order : cases){
        answer = min(answer,simulate(order,reqs));
    }
    
    return answer;
}