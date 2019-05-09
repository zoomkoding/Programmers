#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i = 123; i < 987; i++){
        bool good = true;
        for(int j = 0; j < baseball.size(); j++){
            int strike = 0;
            int ball = 0;
            string n1 = to_string(i);
            string n2 = to_string(baseball[j][0]);
            for(int k = 0; k < 3; k ++){
                if(n1.at(k) == n2.at(k)) {
                    strike ++;
                    continue;
                }
                for(int l = 0; l < 3; l++){
                    if(n1.at(k) == n2.at(l)){
                        ball ++;
                        break;
                    }
                }
            }
            if(strike == baseball[j][1] && ball == baseball[j][2]);
            else {
                good = false;
                break;
            }
        }
        if(good) {
            string s = to_string(i);
            for(int j = 0; j < s.length(); j++){
                if(s.at(j) == '0'){
                    good = false;
                    break;
                }
                for(int k = 0; k < s.length(); k++){
                    if(j == k) continue;
                    if(s.at(j) == s.at(k)){
                        good =false;
                        break;
                    }
                }
            }
            if(good)answer ++;
        }
    }
    return answer;
}
