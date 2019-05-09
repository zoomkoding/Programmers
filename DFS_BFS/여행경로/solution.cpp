#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int t_size = 0;

vector<string> dfs(string s, map<string, priority_queue<string, vector<string>, greater<string>>>m, vector<string> t){
    vector<string> v;
    t.push_back(s);
    if(m[s].empty()) return t;
    vector<string> temp;
    while(!m[s].empty()){
        temp.push_back(m[s].top());
        m[s].pop();
    }
    for(int i = 0; i < temp.size(); i++){
        map<string, priority_queue<string, vector<string>, greater<string>>>_m = m;
        for(int j = 0; j < temp.size(); j++){
            if(i != j)_m[s].push(temp[j]);
        }
        v = dfs(temp[i], _m, t);
        if(v.size() == t_size + 1) break;
    }
    return v;
}

map<string, priority_queue<string, vector<string>, greater<string>>>m;
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    t_size = tickets.size();
    for(int i = 0; i < tickets.size(); i++){
        m[tickets[i][0]].push(tickets[i][1]);
    }
    return dfs("ICN", m, answer);
}
