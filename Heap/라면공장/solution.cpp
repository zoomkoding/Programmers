#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

struct Node{
    int stock;
    int date;
    int index;
    int count;
};

struct cmp{
    bool operator()(Node t, Node u){
        // bool a;
        // if(t.count > u.count) a = true;
        // else if(t.count == u.count){
        //     if(t.index < u.index) a = true;
        //     else a = false;
        // }
        // else a = false;
        // return a;
        return t.count > u.count;
    }
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 100000;
    priority_queue< Node, vector<Node>,  cmp > pq;
    
    Node root;
    root.stock = stock;
    root.date = 0;
    root.index = 0;
    root.count = 0;
    pq.push(root);
    
    while(!pq.empty()){
        Node temp;
        temp = pq.top();
        if(temp.count >= answer - 1)break;
        // cout << "[s, d, i, c] : [" << temp.stock << ", " << temp.date << ", " << temp.index << ", " << temp.count << "]"<<endl;
        pq.pop();
        
        int current_s = temp.stock - (dates[temp.index]-temp.date);
        
        Node child[2];
        child[0].stock = current_s + supplies[temp.index];
        child[0].date = dates[temp.index];
        child[0].count = temp.count+1;
        child[0].index = temp.index+1;
        child[1].stock = current_s;
        child[1].date = dates[temp.index];
        child[1].count = temp.count;
        child[1].index = temp.index+1;
        for(int i = 0; i < 2; i++){
            if(child[i].index == dates.size()) {
                if(child[i].stock >= k - child[i].date){
                    if(answer > child[i].count) answer = child[i].count;
                }
                continue;
            }
            
            current_s = child[i].stock - (dates[child[i].index]-child[i].date);
            if(current_s < 0) continue;
            if(child[i].count >= answer - 1)continue;
            
            // if(current_s >= k - dates[child[i].index]) return child[i].count;
            // cout << "[s, d, i, c] : [" << child[i].stock << ", " << child[i].date << ", " << child[i].index << ", " << child[i].count << "]";
            // cout << " current stock : "<< current_s<< endl;
            
            pq.push(child[i]);
        }
        
        
    }
    
    return answer;
}
