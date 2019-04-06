#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    //2, 22, 222, 2222, 22222
    long long Ns[7] = {
        N,
        N + N*10,
        N + N*10 + N*100,
        N + N*10 + N*100 + N*1000,
        N + N*10 + N*100 + N*1000 + N*10000,
        N + N*10 + N*100 + N*1000 + N*10000 + N*100000,
        N + N*10 + N*100 + N*1000 + N*10000 + N*100000 + N*1000000
        
    };
    
    //map에 저장
    map< long long, int > m;
    vector<long long> v;
    
    //첫 원소만 넣어주고 시작하겠습니다.
    m[N] = 1;
    v.push_back(N);
    
    for(int i = 2; i < 9; i ++){
        int leng =  v.size();
        for(int j = 0; j < leng; j++){
            //꺼낸 원소와 계산에 쓸 숫자
            long long num_out = v[j];
            long long operand = Ns[i-m[num_out]-1];
            long long result = 0;
            //덧셈
            result = num_out + operand;
            
            //number과 같으면 끝내
            if(result == number) return i;
            //안같으면
            else{
                if(m[result] == 0){
                    v.push_back(result);
                    m[result] = i;
                }
                else{
                    if(m[result] > i) m[result] = i;
                }
            }
            
            //뺄셈
            result = num_out - operand;
            //number과 같으면 끝내
            if(result == number) return i;
            //안같으면
            else{
                if(m[result] == 0){
                    v.push_back(result);
                    m[result] = i;
                }
                else{
                    if(m[result] > i) m[result] = i;
                }
            }
            //나눗셈
            result = num_out / operand;
            //number과 같으면 끝내
            if(result == number) return i;
            //안같으면
            else{
                if(m[result] == 0){
                    v.push_back(result);
                    m[result] = i;
                }
                else{
                    if(m[result] > i) m[result] = i;
                }
            }
            //곱셈
            result = num_out * operand;
            //number과 같으면 끝내
            if(result == number) return i;
            //안같으면
            else{
                if(m[result] == 0){
                    v.push_back(result);
                    m[result] = i;
                }
                else{
                    if(m[result] > i) m[result] = i;
                }
            }
            //2->22, 22->22222
            if(Ns[m[num_out]-1] == num_out){
                result = Ns[i-1];
                //number과 같으면 끝내
                if(result == number) return i;
                //안같으면
                else{
                    if(m[result] == 0){
                        v.push_back(result);
                        m[result] = i;
                    }
                    else{
                        if(m[result] > i) m[result] = i;
                    }
                }
            }
        }
    }
    
    return -1;
}
