#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b){
    return a.size()< b.size();
}

bool solution(vector<string> phone_book) {
    for(int i = 0; i < phone_book.size(); i++){
        cout<< i << ":"<< phone_book[i]<< endl;
    }
    int book_size = phone_book.size();
    printf("%d\n", book_size);
    //sorting을 해서 넣어볼까?
    for(int i = 0; i < phone_book.size(); i++){
        //길이가 짧은 애들을 앞으로
        sort(phone_book.begin(), phone_book.end(), compare);
    }
    // printf("%d\n", phone_book.size());
    for(int i = 0; i< book_size; i++){
        for(int j = i + 1; j < book_size; j++){
            int k;
            for(k = 0; k < phone_book[i].length(); k++){
                // printf("i = %d, j = %d, k = %d\n", i, j, k);
                // cout<<phone_book[i]<<endl;
                // cout<<phone_book[j]<<endl;
                if(phone_book[i].at(k) != phone_book[j].at(k)){
                    // cout << "pass"<< endl;
                    break;
                }
            }
            // cout<<phone_book[i].length()<<endl;
            // cout<<k<<endl;
            if(k == phone_book[i].length()) {
                // cout << "return false" << endl;
                return false;
            }
        }
    }
    return true;
}
