#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int** array;
int** ways;
queue<pair<int, int>> q;

void to_array(int dist, int org_i, int org_j, int i, int j){
    if(dist <= array[i][j]){
        if(dist == array[i][j]){
            ways[i][j] += ways[org_i][org_j];
            ways[i][j] %= 1000000007;
        }
        else{
            ways[i][j] = ways[org_i][org_j];
            array[i][j] = dist;
            q.push(make_pair(i, j));
        }
    }
}

int bfs(int m, int n){
    int count = 0;
    q.push(make_pair(1,1));
    while(!q.empty()){
        pair <int,int> r = q.front();
        int cur_dist = array[r.first][r.second];
        if(r.first == m && r.second == n) return ways[r.first][r.second];
        q.pop();
        to_array(cur_dist+1, r.first, r.second, r.first-1, r.second);
        to_array(cur_dist+1, r.first, r.second, r.first+1, r.second);
        to_array(cur_dist+1, r.first, r.second, r.first, r.second-1);
        to_array(cur_dist+1, r.first, r.second, r.first, r.second+1);
    }
    return count;
}


int solution(int m, int n, vector<vector<int>> puddles) {
    array = new int*[m+2];
    ways = new int*[m+2];
    for(int i = 0; i < m+2; i++)array[i] = new int[n+2];
    for(int i = 0; i < m+2; i++)ways[i] = new int[n+2];
    for(int i = 0; i < m+2; i++){
        for(int j = 0; j < n+2; j++) array[i][j] = -1;
    }
    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1; j++){
            array[i][j] = 1000;
            ways[i][j] = 0;
        }
    }
    for(int i = 0; i < puddles.size(); i++)array[puddles[i][0]][puddles[i][1]] = -1;
    array[1][1] = 0;
    ways[1][1] = 1;
    return bfs(m,n);
}
