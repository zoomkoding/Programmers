#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
map<string, int> m_count;
map<string, int> m_1;
map<string, int> m_2;
vector<string> kinds;

bool compare(string a, string b){
    return m[a] > m[b];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0; i < genres.size(); i++){
        int x = m.find(genres[i])->second;
        if(x == m.end()->second) {
            kinds.push_back(genres[i]);
            m[genres[i]] =  plays[i];
            m_count[genres[i]] = 1;
        }
        else {
            m[genres[i]] = x + plays[i];
            m_count[genres[i]] ++;
        }
        
        int num1 = m_1.find(genres[i])->second;
        int num2 = m_2.find(genres[i])->second;
        if(num1 == m_1.end()->second) m_1[genres[i]] = i;
        else {
            if(plays[num1] < plays[i]){
                m_1[genres[i]] = i;
                m_2[genres[i]] = num1;
            }
            else{
                if(num2 == m_2.end()->second) m_2[genres[i]] = i;
                else if(plays[num2] < plays[i]) m_2[genres[i]] = i;
            }
        }
    }
    sort(kinds.begin(), kinds.end(), compare);
    for(int i = 0; i < kinds.size(); i++){
        answer.push_back(m_1[kinds[i]]);
        if(m_count[kinds[i]] > 1) answer.push_back(m_2[kinds[i]]);
    }
    return answer;
}
