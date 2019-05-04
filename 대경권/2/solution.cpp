#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string s = "0";
    int N, x, y;
    cin >> N >> x>> y;
    
    for(int i = 0; i < N-1; i++){
        string temp = "";
        for(int j = 0; j < s.length(); j++)temp += to_string('1'-s.at(j));
        s += temp;
    }
    for(int i = x-1; i < y; i++){
        cout<<s.at(i);
    }
    cout<< endl;
    return 0;
}
