#include <string>
#include <vector>

using namespace std;
string answer = "";

string solution(string number, int k) {
    while(1){
        if(k <= 0) {
            answer += number;
            break;
        }
        else if(number.length() <= k) break;
        char max = '0';
        int max_i = 0;
        for(int i = 0; i <= k; i++){
            if(number[i] > max){
                max = number[i];
                max_i = i;
                if(max == '9') break;
            }
        }
        answer += number[max_i];
        number = number.substr(max_i + 1, number.length());
        k = k - max_i;
    }
    return answer;
}
