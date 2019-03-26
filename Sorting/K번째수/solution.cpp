#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> copy = array;
        int start = commands[i][0]-1;
        int end = commands[i][1];
        int k = commands[i][2];
        
        sort(copy.begin()+start, copy.begin()+end);
        answer.push_back(copy[start+k-1]);
    }
    return answer;
}
