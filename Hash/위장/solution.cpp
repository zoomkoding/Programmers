
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    //맵을 만들어
    int sum = 1;
    map<string, int> m;

    for(int i = 0; i < clothes.size(); i++){
        int value = m.find(clothes[i][1])->second;
        if(value == m.end()->second) m.insert(make_pair(clothes[i][1], 1));
        else m[clothes[i][1]] = value + 1;
    }
    for(auto i = m.begin(); i !=  m.end(); i++){
        sum *= (i->second +1);
    }

    return sum-1;
}
