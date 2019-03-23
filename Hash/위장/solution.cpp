
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    //맵을 만들어
    int sum = 0;
    map<string, int> m;
    vector<int> num;
    map<int, int> count;

    for(int i = 0; i < clothes.size(); i++){
        int value = m.find(clothes[i][1])->second;
        if(value == m.end()->second) m.insert(make_pair(clothes[i][1], 1));
        else m[clothes[i][1]] = value + 1;
    }
    for(auto i = m.begin(); i !=  m.end(); i++)num.push_back(i->second);
    for(int i = 0; i < num.size(); i++){
        count.insert(make_pair(num[i], i));
        sum += num[i];
    }

    
    
    for(int i = 0; i < num.size(); i++){
        map<int, int> temp;
        
        for(auto j = count.begin(); j !=  count.end(); j++){
            for(int k = j->second + 1; k < num.size(); k++){
                int value = j->first*num[k];
                temp.insert(make_pair(value, k));
                sum += value;
            }
        }
        count.clear();
        for(auto j = temp.begin(); j !=  temp.end(); j++){
            count.insert(make_pair(j->first, j->second));
        }
    }
   
    return sum;
}
