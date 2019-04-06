#include <string>
#include <vector>
#include <map>

using namespace std;

map< long long, int > m;
vector<long long> v;
int Ns[7];

bool correct_check(long long result, int number, int i){
    if(result == number) return true;
    if(m[result] == 0){
        v.push_back(result);
        m[result] = i;
    }
    else if(m[result] > i) m[result] = i;
    return false;
}

int solution(int N, int number) {
    m[N] = 1;
    v.push_back(N);
    Ns[0] = N;
    for(int i = 1; i < 7; i++)Ns[i] = N+Ns[i-1]*10;
    for(int i = 2; i < 9; i ++){
        int leng =  v.size();
        for(int j = 0; j < leng; j++){
            long long num_out = v[j];
            int diff = i-m[num_out];
            for(auto iter=m.begin();iter!=m.end();iter++){
                if(iter->second != diff || iter->first == 0) continue;
                long long operand = iter->first;
                if(correct_check(num_out + operand, number, i)) return i;
                if(correct_check(num_out - operand, number, i)) return i;
                if(correct_check(num_out / operand, number, i)) return i;
                if(correct_check(num_out * operand, number, i)) return i;
                if(Ns[m[num_out]-1] == num_out){
                    if(correct_check(Ns[i-1], number, i)) return i;
                }
            }
        }
    }
    return -1;
}
