#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int i = 0;
    int count = 0;
    for(int i = 1; i < name.length(); i++){
        if(name.at(i) == 'A') count++;
    }
    while(1){
        if(name.at(i) < 'N') answer+= name.at(i) - 'A';
        else answer+= 13 - (name.at(i) - 'N');
        name.at(i) = 'A';
        count++;
        if(count == name.length()) return answer;
        int j = 1;
        while(1){
            if(name.at((i-j + name.length())%name.length()) != 'A') {
                i = (i-j + name.length())%name.length();
                answer += j;
                break;
            }
            if(name.at((i+j)%name.length())!= 'A'){
                i = (i+j)%name.length();
                answer += j;
                break;
            }
            j ++;
        }
    }
    
}
