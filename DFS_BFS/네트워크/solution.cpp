#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> computers;
queue<int> q;
bool *visited;
int n;
int count = 0;

void bfs(int index){
    q.push(index);
    visited[index] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0 ; i < n ; i++){
            if(computers[temp][i] == 1 && !visited[i] && i != temp ){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int _n, vector<vector<int>> _computers) {
    computers = _computers;
    n = _n;
    visited = new bool[n];
    for(int i = 0; i < n; i ++) visited[i] = false;
    
    for(int i = 0; i < n; i++){
        if(!visited[i]) {
            cout << i << endl;
            bfs(i);
            count++;
        }
    }
    return count;
}
