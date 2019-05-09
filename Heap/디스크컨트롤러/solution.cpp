#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare1 {
    bool operator()(vector<int> a, vector<int> b){
        return a[0] > b[0];
    }
};

struct compare2 {
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int finished = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, compare2> pq_time;
    priority_queue<vector<int>, vector<vector<int>>, compare1> pq_start;
    for(int i = 0; i < jobs.size(); i++){
        pq_start.push(jobs[i]);
    }
    while(finished != jobs.size()){
        while(!pq_start.empty()){
            vector<int> cand = pq_start.top();
            if(cand[0] > time) break;
            pq_start.pop();
            pq_time.push(cand);
        }
        if(pq_time.empty()){
            time = pq_start.top()[0];
            continue;
        }
        vector<int> temp = pq_time.top();
        pq_time.pop();
        time += temp[1];
        answer += time - temp[0];
        finished ++;
    }
    return answer/jobs.size();
}
