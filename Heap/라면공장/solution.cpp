#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue< int > pq;
    int dates_diff = dates[0];
    for(int i = 0; i < dates.size(); i++){
        stock -= dates_diff;
        if(stock >= k - dates[i]) break;
        
        if(i == dates.size()-1) dates_diff = k - dates[i];
        else dates_diff = dates[i+1] - dates[i];
        
        pq.push(supplies[i]);
        while(stock < dates_diff){
            answer ++;
            stock += pq.top();
            pq.pop();
        }
    }
    return answer;
}
