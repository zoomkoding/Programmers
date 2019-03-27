#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool myfunction (int a,int b) { 
    string str_a = to_string(a);
    string str_b = to_string(b);
    int time;
    int who;
    if(str_a.length() < str_b.length()){
        time = str_a.length();
        who = 1;
    }
    else{
        time = str_b.length();
        who = 2;
    }
    for(int i = 0; i < time; i++){
        if(str_a[i] > str_b[i]) return true;
        else if(str_a[i] < str_b[i]) return false;
    }    
    if(who == 1){
        if(str_a[0]>str_b[str_b.length()-1]) return true;
        else return false;
    }
    else{
        if(str_b[0]<str_a[str_a.length()-1]) return true;
        else return false;
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    sort (numbers.begin(), numbers.end(), myfunction);
    for(int i = 0; i < numbers.size(); i++){
        cout<<numbers[i]<<endl;
    }
    for(int i = 0; i < numbers.size(); i++){
        answer += to_string(numbers[i])
    }
    return answer;
}
