#include <stdio.h>
#include <stdlib.h>
#include <time.h>




typedef struct item{
  int benefit;
  int weight;
  float value;
}Item;

void swap(Item* a, Item* b);
void quick_sort(Item* array, int start, int end);
void greedy(Item* array, int n, int w);
void dp(Item* array, int n, int w);
void bandb(Item* array, int n, int w);




void swap(Item* a, Item* b){
    Item tmp= *a;
    *a=*b;
    *b=tmp;
}
void quick_sort(Item* array, int start, int end){
 
    if(start>=end) return;
 
    int mid=(start+end)/2;
    float pivot=array[mid].value;
 
    swap(&array[start],&array[mid]);
 
    int p=start+1,q=end;
 
    while(1){
        while(array[p].value>=pivot){ p++; }
        while(array[q].value<pivot){ q--; }
 
        if(p>q) break;
 
        swap(&array[p],&array[q]);
    }
 
    swap(&array[start],&array[q]);
 
    quick_sort(array,start,q-1);
    quick_sort(array,q+1,end);
 
}

void greedy(Item* array, int n, int w){
  float benefit = 0;
  int left = w;
  for(int i = 0; i < n; i++){
    //만약 원소가 넘겨버리면 쪼개서 넣어
    if(array[i].weight > left) {
      benefit += array[i].value * left;
      break;
    }
    //안넘기면 다 넣어
    else{
      left -= array[i].weight;
      benefit += array[i].benefit;
      if(left == 0) break;
    }
  }
  printf("greedy benefit : %f\n", benefit);
}

void dp(Item* array, int n, int W){
  int ** B;
  B = (int**) malloc ((n+1) * sizeof(int*));
  for(int i = 0; i < n+1; i++) B[i] = (int*) malloc (W * sizeof(int));
  
  for(int i = 0; i < W; i++)B[0][i] = 0;
  for(int i = 1; i < n + 1; i++){
    B[i][0] = 0;
    for(int w = 1; w < W; w++){
      int _w = array[i-1].weight;
      int _b = array[i-1].benefit;
      if(_w <= w){
        if(_b+B[i-1][w-_w]>B[i-1][w]) B[i][w] = _b+B[i-1][w-_w];
        else B[i][w] = B[i-1][w];
      }
      else B[i][w] = B[i-1][w];
    }
  }
  
  printf("dp benefit : %d\n", B[n][W-1]);

}

typedef struct NodeStruct
{
    int weight;
    int benefit;
    int index;
    float bound;
}Node;



Node queue[4];
int front, rear;
int qsize = 4;

void init_queue(void){
    front = rear = 0;
}

void clear_queue(void){
    front = rear;
}
void push(Node k){
    // 큐가 꽉차있는지 확인
    if ((rear + 1) % qsize == front){
        printf("\n   Queue overflow.");
        return;
    }

    queue[rear] = k;
    rear = ++rear % qsize;
}

Node pop(void){
    Node n;
    if (front == rear){
        n.benefit = -1;
        return n;
    }

    n = queue[front];
    front = ++front % qsize;
    return n;
}

// typedef struct NodeStruct
// {
//     int weight;
//     int benefit;
//     int index;
//     float bound;
// }Node;

void bandb(Item* array, int n, int w){
  init_queue();
  float max_benefit = 0.0;
  int weight = 0;
  //queue 사이즈 할당해주기
  Node root;
  //root node 넣어줘
  root.weight = 0;
  root.benefit = 0;
  root.index = 0;
  for(int i = 0; i < n; i++){
    if(weight+array[i].weight > w){
      root.bound += (w-weight)*array[i].value;
      break;
    }
    else {
      root.bound += array[i].benefit;
      weight += array[i].weight;
    }
  }
  push(root);

  //q에서 꺼낸 원소가 -1이 아니라면 반복
  int t = 0;
  while(1){
    // printf("time stamp %d max_benefit %.1f\n", t, max_benefit);
    t ++ ;
    Node temp = pop();
    Node child[2];
    if(temp.benefit == -1) break;
    

    int index = temp.index + 1;
    
    // printf("parent index : %d, benefit : %d, weight : %d, bound : %f\n", temp.index, temp.benefit, temp.weight, temp.bound);
    if(temp.bound < max_benefit){
      // printf("parent rejected\n");
      continue;
    }
    if(temp.index == n-1)continue;
    
    child[0].weight = temp.weight + array[index-1].weight;
    child[0].benefit = temp.benefit + array[index-1].benefit;
    child[1].weight = temp.weight;
    child[1].benefit = temp.benefit;

    //넣기로 하고 하나는 안넣기로해서 두번 작업해
    //꺼낸 원소의 weight과 w를 비교해서 넘으면 continue
    for(int i = 0; i < 2; i++){

      child[i].index = index;
      child[i].bound = child[i].benefit;


      // printf("child[%d] index : %d, benefit : %d, weight : %d\n", i, child[i].index, child[i].benefit, child[i].weight);
      if(w < child[i].weight){
        // printf("child[%d] rejected for size\n", i);
        continue;
      } 
      //꺼낸 원소의 bound를 구하고 
      weight = child[i].weight;
      for(int j = index; j < n; j++){
        if(weight+array[j].weight > w){
          child[i].bound += (w-weight)*array[j].value;
          break;
        }
        else {
          child[i].bound += array[j].benefit;
          weight += array[j].weight;
        }
      }
      //max_benefit보다 작으면 continue
      if(child[i].bound < max_benefit) {
        // printf("child[%d] rejected for bound\n", i);
        continue;
      }
      //benefit을 구하고 max_benefit 보다 크면 max_benefit 업데이트
      if(child[i].benefit > max_benefit)max_benefit = child[i].benefit;
      //push 해줘 
      push(child[i]);
      
    }
  }
    
  //다돌았으면 결과 리턴해
  printf("bnb benefit : %f\n", max_benefit);

}

int main(void) {
  srand(time(NULL)); 
  int W;
  int n[9] = {10, 100, 500, 1000, 3000, 5000, 7000, 9000, 10000};
  int samp_bi[4] = {40, 30, 50, 10};
  int samp_wi[4] = {2, 5, 10, 5};
  float samp_val[4] = {20, 6, 5, 2};
  Item* items;
  items = (Item*) malloc (n[0]*sizeof(Item));
  W = 16;
  for(int i = 0; i < n[0]; i++){
    items[i].benefit = rand() % 300 + 1;  
    items[i].weight = rand() % 100 + 1;
    items[i].value = (float)items[i].benefit / items[i].weight;
    printf("%d번째 benefit: %d, weight: %d, v/w: %f\n", i,items[i].benefit, items[i].weight, items[i].value);
  }  
  // for(int i = 0; i < n[0]; i++){
  //   items[i].benefit = samp_bi[i];
  //   items[i].weight = samp_wi[i];
  //   items[i].value = samp_val[i];
  // }

  quick_sort(items, 0, n[0]-1);
  printf("\n\n");
  for(int i = 0; i < n[0]; i++) printf("%d번째 benefit: %d, weight: %d, v/w: %f\n", i,items[i].benefit, items[i].weight, items[i].value);

  // greedy(items, n[0], W);
  dp(items, n[0], W);
  bandb(items, n[0], W);
}
