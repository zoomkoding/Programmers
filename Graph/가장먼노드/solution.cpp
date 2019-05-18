#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int * d = new int[n + 1];
    queue<int> q;
    vector<queue<int>> v;
    for(int i = 0; i < n + 1; i++){
        v.push_back(queue<int>());
        d[i] = 50000;
    }
    d[1] = 0;
    for(int i = 0; i < edge.size(); i++){
        v[edge[i][0]].push(edge[i][1]);
        v[edge[i][1]].push(edge[i][0]);
    }
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        while(!v[x].empty()){
            int y = v[x].front();
            v[x].pop();
            q.push(y);
            if(d[x] + 1 < d[y]) d[y] = d[x] + 1;
        }
    }
    int max = 0;
    for(int i = 1; i < n + 1; i++){
        if(d[i] > max) max = d[i];
    }
    
    for(int i = 1; i < n + 1; i++){
        if(d[i] == max) answer ++;
    }
    return answer;
}
