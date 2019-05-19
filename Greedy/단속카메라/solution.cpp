#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int time = -30000;
    sort(routes.begin(), routes.end(), compare);
    for(int i = 0; i < routes.size(); i++){
        if(routes[i][0] <= time && time <= routes[i][1]) continue;
        time = routes[i][1];
        answer ++;
    }
    return answer;
}
