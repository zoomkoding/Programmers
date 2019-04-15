#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> array = triangle;
    array[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j < i; j++){
            int num1 = array[i-1][j]+ triangle[i][j];
            if(j == 0) array[i][j] = num1;
            else if(num1> array[i][j]) array[i][j] = num1;
            array[i][j+1] = array[i-1][j] + triangle[i][j+1];
        }
    }
    int max = 0, leaf = triangle.size()-1;
    for(int i = 0; i < array[leaf].size(); i++){
        if(array[leaf][i] > max) max = array[leaf][i];
    }
    return max;
}
