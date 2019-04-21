#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i= 0; i < scoville.size(); i++)pq.push(scoville[i]);
    int times = 0;
    while(!pq.empty()){
        if(pq.top() < K && pq.size() ==1) break;
        int num[2];
        for(int i = 0 ; i < 2; i++){
            num[i] = pq.top();
            pq.pop();
        }
        if(num[0] >= K) return times;
        pq.push(num[0]+num[1]*2);
        times++;
    }
    return -1;
    }
