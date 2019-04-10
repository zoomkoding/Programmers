#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int no = 0;
    for(int i = 0; i < lost.size(); i++){
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] == reserve[j]){
                reserve[j] = -1;
                lost[i] = -1;
            }
        }
    }
    for(int i = 0; i < lost.size(); i++){
        if(lost[i] == -1) continue;
        for(int j = 0; j < reserve.size(); j++){
            if(lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) {
                reserve[j] = -1;
                lost[i] = -1;
                break;
            }
        }
        if(lost[i] != -1) no ++;
    } 
    return n - no;
}
