#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;


bool solution(vector<string> phone_book) {
    int book_size = phone_book.size();
    //max, min은 검색하는 for문을 위해서 만듬
    map<string, int> m;
    int max = 0;
    int min = phone_book[0].length();
    
    //해쉬맵에 넣어
    for(int i = 0; i < phone_book.size(); i++){
        int len = phone_book[i].length();
        if(len > max) max = len;
        if(len < min) min = len;
        m.insert(make_pair(phone_book[i], 1) );
    }
    
    //글자수 만큼을 찾아
    for(int i = min; i <= max; i++){
        for(int j = 0; j < phone_book.size(); j++){
            //string의 길이가 글자수보다 짧으면 패스
            if(phone_book[j].length()<i) continue;
            string x = phone_book[j].substr(0, i);
            //substr이 string이랑 같으면 패스
            if(x.compare(phone_book[j]) == 0) continue;
            //해쉬맵에 존재하면 return false
            if(m.find(x)->second == 1){
                return false;
            }
        }
    }
    return true;
}
