#include <string>
#include <vector>
#include <math.h>

using namespace std;
string numbers;
vector<int> v;
vector<int> answers;
int num[10] = {0,};

void num_find(int n, string s){
    if(n == numbers.length()) return;
    for(int i = 0; i < numbers.length(); i++){
        string temp = s + numbers.at(i);
        v.push_back(stoi(temp));
        num_find(n+1, temp);
    }
}

bool check(int n){
    string a  = to_string(n);
    int temp[10] = {0,};
    for(int i = 0; i < a.length(); i++){
        temp[a.at(i)-'0'] ++;
    }
    for(int i = 0; i < 10; i++){
        if(temp[i] > num[i]) return false;
    }
    
    return true;
}

int solution(string _numbers) {
    numbers = _numbers;
    int answer = 0;
    for(int i = 0; i < numbers.length(); i++)num[numbers.at(i)-'0'] ++;
    num_find(0, "");
    for(int i = 0; i < v.size(); i++){
        if(v[i] < 2) continue;
        for(int j = 0; j < answers.size(); j++){
            if(answers[j] == v[i]) {
                v[i] = -1;
                break;
            }
        }
        if(v[i] == -1) continue;
        for(int j = 2; j < v[i]; j++){
            if(v[i]%j == 0) {
                v[i] = -1;
                break;
            }
        }
        if(v[i] != -1){
            if(check(v[i])) {
                answer ++;
                answers.push_back(v[i]);
            }
        }
    }
    return answer;
}
