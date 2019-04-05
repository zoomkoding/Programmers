#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int solution(int N, int number) {
    vector<int> v;
    vector<int> c;
    int start = 0;
    int end = 2;
    v.push_back(N);
    c.push_back(1);
    v.push_back(N+10*N);
    c.push_back(2);
    
    for(int i = 0; i < 8; i++){
        for(int j = start; j < end; j++){
            //덧셈확인
            if(v[j]+N == number){
                cout << v[j] << "+" << N << endl; 
                return c[j]+1;
            } 
            else {
                v.push_back(v[j]+N);
                c.push_back(c[j]+1);
            }
            //뺄셈확인
            if(v[j]-N == number){
                cout << v[j] << "-" << N << endl; 
                return c[j]+1;
            } 
            else{
                v.push_back(v[j]-N);
                c.push_back(c[j]+1);
            } 
            //나눗셈확인
            if(v[j]/N == number){
                cout << v[j] << "/" << N << endl; 
                return c[j]+1;
            } 
            else {
                v.push_back(v[j]/N);
                c.push_back(c[j]+1);

            }
            //곱셈확인
            if(v[j]*N == number){
                cout << v[j] << "*" << N << endl; 
                return c[j]+1;
            } 
            else {
                v.push_back(v[j]*N);
                c.push_back(c[j]+1);
            }
            
            
             int NN= N*10+N;
            //덧셈확인
            if(v[j]+NN == number){
                cout << v[j] << "+" << NN << endl; 
                return c[j]+2;
            } 
            else {
                v.push_back(v[j]+NN);
                c.push_back(c[j]+2);
            }
            
            //뺄셈확인
            if(v[j]-NN == number){
                cout << v[j] << "-" << NN << endl; 
                return c[j]+2;
            } 
            else {
                v.push_back(v[j]-NN);
                c.push_back(c[j]+2);
            }
            //나눗셈확인
            if(v[j]/NN == number){
                cout << v[j] << "/" << NN << endl; 
                return c[j]+2;
            } 
            else{
                v.push_back(v[j]/NN);
                c.push_back(c[j]+2);
            } 
            //곱셈확인
            if(v[j]*NN == number){
                cout << v[j] << "*" << NN << endl; 
                return c[j]+2;
            } 
            else {
                v.push_back(v[j]*NN);
                c.push_back(c[j]+2);
            }
            
        }    
        start+=pow(8, i);
        end+=pow(8, i+1);
    }
    
    
    return -1;
}
