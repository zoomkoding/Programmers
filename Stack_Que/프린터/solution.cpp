#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> q;
    map<int, int> m;
    int max = 0;
    int order = 0;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push(i);
        if(m[priorities[i]] == m.end()->second) m[priorities[i]] = 1;
        else m[priorities[i]] ++;
        if(priorities[i] > max) max = priorities[i];
    }
    
    while(!q.empty()){
        int q_front = q.front();
        int prior = priorities[q_front];
        q.pop();
        
        if(prior == max){
            order ++;
            if(q_front == location) return order;
            if(--m[prior] == 0){
                for(int i = prior-1; i > 0; i--){
                    if(m[i] != m.end()->second){
                        max = i;
                        break;
                    }
                }
            }
        }
        else q.push(q_front);
    }
    return order;
}
