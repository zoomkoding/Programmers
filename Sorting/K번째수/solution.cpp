#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i< commands.size(); i++){
        int min= 101;
        int bound = 0;
        for(int j = 0; j < commands[i][2]; j++){
            min = 101;
            for(int k = commands[i][0]-1; k <= commands[i][1]-1; k++){
                if(array[k]<min && array[k]>bound)min = array[k];
            }
            bound = min;
        }
        answer.push_back(min);
    }
    return answer;
}
