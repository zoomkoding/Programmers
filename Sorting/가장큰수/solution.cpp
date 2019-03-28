#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool myfunction(int a, int b){
    string str_a = to_string(a);
    string str_b = to_string(b);
    return stoi(str_a+str_b) > stoi(str_b+str_a);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), myfunction);
    for(int i = 0; i < numbers.size(); i++)answer+=to_string(numbers[i]);
    if(answer.compare(0,1,"0")==0)return "0";
    return answer;
}
