#include <string>
#include <vector>

using namespace std;

vector<int> numbers;
int target;

int dfs(int sum, int depth){
    if(depth == numbers.size()){
        if(sum == target) return 1;
        else return 0;
    }
    return dfs(sum + numbers[depth], depth+1) + dfs(sum - numbers[depth], depth+1);
}

int solution(vector<int> _numbers, int _target) {
    numbers = _numbers;
    target = _target;
    return dfs(0, 0);
}
