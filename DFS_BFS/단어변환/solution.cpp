#include <string>
#include <vector>

using namespace std;

string target;

int dfs(string begin, string target, int depth, vector<string> words){
    if (begin.compare(target) == 0) return depth;
    int times;
    int value = 100000;
    int min = 100000;
    for(int i = 0; i < words.size(); i++){
        int count = 0;
        for(int j = 0; j < begin.length(); j++){
            if(begin.at(j) == words[i].at(j)) count++;
        }
        if(count == begin.length() - 1) {
            string send = words[i];
            words[i] = "                        ";
            value = dfs(send, target, depth+1, words);
        }
        if(value < min) min = value;
    }
    return min;
}

int solution(string begin, string target, vector<string> words) {
    int distance = dfs(begin, target, 0, words);
    if(distance == 100000) return 0;
    else return distance;
}
