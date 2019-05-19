#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> costs;

struct subset {
    int parent;
    int rank;
};

struct subset *subsets;

int find(int i){
    if(subsets[i].parent != i)subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent;
}

void Union(int x, int y){
    int xroot = find(x);
    int yroot = find(y);
    if(subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank ++;
    }
}

int isCycle(int t){
    int x = find(costs[t][0]);
    int y = find(costs[t][1]);
    if (x == y) return 1;
    Union(x, y);
    return 0;
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> _costs) {
    
    subsets = (struct subset*) malloc( n * sizeof(struct subset) );
    for (int v = 0; v < n; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    costs = _costs;
    
    int answer = 0;
    int count = 0;
    
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < costs.size(); i++){
        if(!isCycle(i)){
            answer += costs[i][2];
            count ++;
            if(count == n - 1) return answer;
        }
    }
    
    return answer;
}
