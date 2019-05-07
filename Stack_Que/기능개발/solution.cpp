#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int current_w = 0;
    int time = 0;
    int i = 0;
    while(i != truck_weights.size()){
        time ++;
        if(bridge.size() == bridge_length){
            if(bridge.front() != -1) current_w -= bridge.front();
            bridge.pop();
        }
        if(current_w + truck_weights[i] <= weight){
            current_w += truck_weights[i];
            bridge.push(truck_weights[i]);
            i++;
        }
        else bridge.push(-1);
    }
    time += bridge_length;
    return time;
}
