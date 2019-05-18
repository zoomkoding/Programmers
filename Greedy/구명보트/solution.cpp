#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size();
    sort(people.begin(), people.end());
    int s = people.size() - 1;
    for(int i = 0; i < people.size(); i++){
        bool exist = false;
        for(int j = s; j > i; j--){
            if(people[i] + people[j] <= limit){
                exist = true;
                answer--;
                s = j - 1;
                break;
            }
        }
        if(!exist) return answer;
    }
    return answer;
}
