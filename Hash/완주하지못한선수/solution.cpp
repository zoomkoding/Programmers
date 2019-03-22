#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    //completion을 넣어
    for(int i = 0; i < completion.size(); i++){
        int x = m.find(completion[i])->second;
        if(x == m.end()->second) m.insert(make_pair(completion[i], 1) );
        else m[completion[i]]=x+1;
    }
    
    //participant를 검색해
    for(int i = 0; i < participant.size(); i++){
        int x = m.find(participant[i])->second;
        if(x == 0 || x == m.end()->second) return participant[i];
        else m[participant[i]]=--x;
    }
    string answer = "";
    return answer;
}
