## 문제

조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

>* ▲ - 다음 알파벳
>* ▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
>* ◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
>* ▶ - 커서를 오른쪽으로 이동

예를 들어 아래의 방법으로 JAZ를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.

따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.

만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

**제한사항**

>* name은 알파벳 대문자로만 이루어져 있습니다.
>* name의 길이는 1 이상 20 이하입니다.

## 문제 이해

>* 모든 문자의 시작은 A이고 각 문자를 찾고 커서를 이동시키며 최소한으로 움직이는 방법을 구하는 문제이다.
>* 사실상 다 문제 안되는데 A가 문제이다.
>* JAN 같은 경우에는 A를 바꿀 필요가 없으므로 J를 바꾼후 N을 바꾸러 왼쪽으로 한번만 이동하면 끝이다.
>* 첫 글자를 만들고 왼쪽으로 갈지 오른쪽으로 갈지 정하는게 문제인듯 하다.



## Greedy Algorithm 활용 코드 (복잡도: O(n^2))

    #include <string>
    #include <vector>
    #include <iostream>

    using namespace std;

    int solution(string name) {
    int answer = 0;
    bool* visited = new bool[name.length()];
    for(int i = 0 ; i < name.length(); i++){
    if(name.at(i) == 'A') visited[i] = true;
    else visited[i] = false;

    }
    int i = 0;
    while(1){
    visited[i] = true;
    if(name.at(i) < 'N') answer+= name.at(i) - 'A';
    else answer+= 13 - (name.at(i) - 'N');
    int d = 1;
    while(1){
    if(i+d == name.length()) return answer;
    int up = i + d;
    int down = (name.length() + (i - d)) % name.length();
    if(!visited[up]) {
    i = up;
    answer += d;
    break;
    }
    else if(!visited[down]){
    i = down;
    answer += d;
    break;
    }
    else d ++;
    }

    }
    return answer;
    }

## 느낀점

>* 언제 그리디 알고리즘을 쓰는 것이 좋은지 아직 감이 잘 안온다.
>* 뭔가 직관적인 듯하면서도 아닌 것 같기도 한 애매함이 있다.
>* 유진이랑 잠깐 같이 봤는데 역시 유진이는 대단하다.
