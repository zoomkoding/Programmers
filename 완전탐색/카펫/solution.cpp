#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    for(int i = 1; i < red + 1; i++){
        if(red % i == 0){
            int j = red / i;
            if((i + 2) * (j + 2) == brown + red){
                answer.push_back(j + 2);
                answer.push_back(i + 2);
                break;
            }
        }
    }
    return answer;
}
