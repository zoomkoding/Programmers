#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    bool* visited = new bool[name.length()];
    for(int i = 0 ; i < name.length(); i++){
        if(name.at(i) == 'A') visited[i] = true;
        else visited[i] = false;
        
    }
    int i = 0;
    while(1){
        visited[i] = true;
        if(name.at(i) < 'N') answer+= name.at(i) - 'A';
        else answer+= 13 - (name.at(i) - 'N');
        int d = 1;
        while(1){
            if(i+d == name.length()) return answer;
            int up = i + d;
            int down = (name.length() + (i - d)) % name.length();
            if(!visited[up]) {
                i = up;
                answer += d;
                break;
            }
            else if(!visited[down]){
                i = down;
                answer += d;
                break;
            }
            else d ++;
        }
        
    }
    return answer;
}
