#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for(int i = 0; i < heights.size(); i++){
        int count = 0;
        for(int j = i ; j > -1; j--){
            if(heights[i] < heights[j]) {
                count = j+1;
                break;
            }
        }
        answer.push_back(count);
    }
    return answer;
}
