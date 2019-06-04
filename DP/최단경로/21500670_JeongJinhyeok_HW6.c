#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NUM 10
#define INF 100000
#define NIL -1
#define MAX_SIZE 10000
#define TRUE 1
#define FALSE 0
// Busan	Daegu	Daejeon	Gangeung	Gwangju	Jeonju	Jinju	Pohang	Seoul  Wonju

int arr[NUM][NUM];
int result[3][NUM][NUM];
float t[3];
int d[NUM];
int p[NUM];
int ex[MAX_SIZE];
int ey[MAX_SIZE];
int ec = 0;
char algo[3][100] = {"Bellman Ford", "Dijkstra", "Floyd"};
char cities[NUM][100] = {"Busan", "Daegu", "Daejeon", "Gangeung", "Gwangju", "Jeonju", "Jinju", "Pohang", "Seoul", "Wonju"};
 
int heap[MAX_SIZE];
int size;

void heap_init() {
    size = 0;
}

void heap_swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int push(int value) {
    if (size + 1 > MAX_SIZE) return 0;
    heap[size] = value;
    int current = size;
    int parent = (size - 1) / 2;
    while (current > 0 && d[heap[current]] < d[heap[parent]]) {
        heap_swap(&heap[current], &heap[parent]);
        current = parent;
        parent = (parent - 1) / 2;
    }
    size++;
    return 1;
}

int pop() {
    if (size <= 0) return -1;
    int ret = heap[0];
    size--;

    heap[0] = heap[size];
    int current = 0;
    int leftChild = current * 2 + 1;
    int rightChild = current * 2 + 2;
    int maxNode = current;

    while (leftChild < size) {
        if (d[heap[maxNode]] > d[heap[leftChild]]) maxNode = leftChild;
        if (rightChild < size && d[heap[maxNode]] > d[heap[rightChild]]) maxNode = rightChild;
        if (maxNode == current)break;
        else {
            heap_swap(&heap[current], &heap[maxNode]);
            current = maxNode;
            leftChild = current * 2 + 1;
            rightChild = current * 2 + 2;
        }
    }   
    return ret;
}

void decrease_key(int index){
    int i = 0;
    for(i = 0; i < size; i++){
        if(heap[i] == index) break;
    }
    while(d[heap[(i-1)/2]] > d[heap[i]]){
        heap_swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void readfile(){
    FILE *pFile = NULL;
    int lc = 0;
    int wc = 0;
	pFile = fopen( "hw6_2019.data", "r" );
	if( pFile != NULL )
	{
		char strTemp[255];
		char *pStr;

		while( !feof( pFile ) )
		{
			pStr = fgets( strTemp, sizeof(strTemp), pFile );
            if(lc == 0) {
                lc++;
                continue;
            }
            wc = 0;
            char *ptr = strtok(pStr, " \n\t");
            while(ptr != NULL){
                if(wc > 10) break;
                if(wc!= 0){
                    
                    if(strncmp(ptr,"INF", 3)==0) arr[lc-1][wc-1] = INF;
                    else {
                        arr[lc-1][wc-1] = atoi(ptr);
                        if(atoi(ptr) != 0){
                            ex[ec] = lc-1;
                            ey[ec] = wc-1;
                            ec++;
                        }
                        
                    }
                }
                ptr = strtok(NULL, " \n\t");
                wc++;
            }
            lc ++;
		}
		fclose( pFile );
	}
}

void init(int src){
  for(int i = 0; i < NUM; i++){
    p[i] = NIL;
    d[i] = INF;
  }
  d[src] = 0;
}

int relax(int u, int v, int w){
    if(d[v] > d[u] + w) {
        d[v] = d[u] + w;
        decrease_key(v);
        p[v] = u;
        return 1;
    }
    return 0;
}

int bellman_ford(int src){
  init(src);
  for(int i = 0; i < ec; i++){
    for(int j = 0; j < ec; j++) relax(ex[j], ey[j], arr[ex[j]][ey[j]]);
  }
  for(int i = 0; i < ec; i++){
    if(d[ey[i]] > d[ex[i]] + arr[ex[i]][ey[i]]) return FALSE;
  }

  for(int i = 0; i < NUM; i++) result[0][src][i] = d[i];

  return TRUE;
}

int dijkstra(int src){
  init(src);
  heap_init();
  for(int i = 0; i < NUM; i++) push(i);
  while(size != 0){
    int u = pop();
    for(int i = 0; i < NUM; i++) relax(u, i, arr[i][u]);
  }
  for(int i = 0; i < NUM; i++) result[1][src][i] = d[i];
  return TRUE;
}

int floyd_warshall(){
    int D[NUM][NUM];
for(int i = 0; i < NUM; i++){
    for(int j = 0; j < NUM; j++)D[i][j] = arr[i][j];
}

for(int k = 0; k < NUM; k++){
    for(int i = 0; i < NUM; i++){
        for(int j = 0; j < NUM; j++){
            if(D[i][k] + D[k][j] < D[i][j]) D[i][j] = D[i][k] + D[k][j];
            else D[i][j] = D[i][j];
        }
    }
}
for(int i = 0; i < NUM; i++){
    for(int j = 0; j < NUM; j++) result[2][i][j] = D[i][j];
} 

return TRUE;
}


void print(){
    for(int i = 0; i < 3; i++){
        printf("\nIt took %.3f seconds to compute shortest path between cities with %s algorithm as follows.\n", t[i]/1000, algo[i]);
        printf("%10s ", "");
        for(int j = 0; j < NUM; j++)printf("%10s ", cities[j]);
        printf("\n");
        for(int j = 0; j < NUM; j++){
            printf("%10s ", cities[j]);
            for(int k = 0; k < NUM; k++)printf("%10d ", result[i][j][k]);
            printf("\n");
        }
        printf("\n");

    }
    
}

int main(void) {
    readfile();
    clock_t start, end;
    for(int i = 0; i < 3; i++){
        start = clock();
        if(i == 0) for(int i = 0; i < NUM; i++) bellman_ford(i);
        else if(i == 1) for(int i = 0; i < NUM; i++) dijkstra(i);
        else floyd_warshall();
        end = clock();
        t[i] = (float)(end - start);
    }
    print();
    

    return 0;
}

 
