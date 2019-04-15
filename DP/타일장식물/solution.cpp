#include <string>
#include <vector>
#include <stack>

using namespace std;

long long solution(int N) {
    long long num1 = 1;
    long long num2 = 1;
    for(int i = 2; i <= N; i++){
        long long temp = num1 + num2;
        num2 = num1;
        num1 = temp;
    }
    
    return 2*(num1+num2);
}
