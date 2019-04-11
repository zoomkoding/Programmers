#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string arrangement) {
    stack <int> s;
    int top;
    int count = 0;
    for(int i = 0; i < arrangement.length(); i++){
        if(arrangement.at(i) == '(') s.push(0);
        else{
            int num = 0;
            while(1){
                top = s.top();
                s.pop();
                if(top == 0){
                    if(num == 0) s.push(1);
                    else {
                        count += num + 1;
                        s.push(num);
                    }
                    break;
                }
                else num += top;
            }
        }
    }
    return count;
}
