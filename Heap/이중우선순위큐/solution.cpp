#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq_m;
    priority_queue< int > pq_M;
    int n = 0;
    for(int i = 0; i < operations.size(); i++){
        if(n == 0){
            while(!pq_M.empty())pq_M.pop();
            while(!pq_m.empty())pq_m.pop();
        }
        int num = stoi(operations[i].substr(1,operations[i].length()));
        if(operations[i].at(0) == 'I'){
            pq_M.push(num);
            pq_m.push(num);
            n ++;
        }
        else if(operations[i].at(0) == 'D'){
            if(n == 0) continue;
            if(num == 1 && !pq_M.empty()) pq_M.pop();
            else if(num == -1 && !pq_m.empty()) pq_m.pop();
            n --;
            
        }
    }
    if(n == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq_M.top());
        answer.push_back(pq_m.top());
    }
    return answer;
}
