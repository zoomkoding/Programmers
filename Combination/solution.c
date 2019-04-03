#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long recursive(int n, int k){
  if(n >= 0){
    if(k == n || k == 0) return 1;
  }
  if(k > 0 && k < n) return recursive(n-1, k-1) + recursive(n-1, k);
  return 0;
} 

long long dynamic(int n, int k){
  long long **arr = (long long **)malloc((n+1) * sizeof(long long *)); 
	for (int i=0; i<n+1; i++) 
		arr[i] = (long long *)malloc((k+1) * sizeof(long long)); 

  for(int i = 1; i < k+1; i++) arr[i][i] = 1;
  for(int i = 1; i < n+1; i++) arr[i][0] = 1;

  for(int i = 2; i < n+1; i++){
    for(int j = 1; j < k+1; j++) arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
  }
  return arr[n][k];

}

int main(void) {
  int n, k;
  long long recur_result, dynam_result;
  float recur_time, dynam_time;
  time_t start, end;

  printf("put n, k value : ");
  scanf("%d %d", &n, &k);

  start = time(NULL); 
  recur_result = recursive(n, k);
  end = time(NULL);
  recur_time = (double)(end - start);
  
  start = time(NULL); 
  dynam_result = dynamic(n, k);
  end = time(NULL);
  dynam_time = (double)(end - start);

  printf("recursive time : %.4f result : %lli\n", recur_time, recur_result);
  printf("dynamic time : %.4f result : %lli\n", dynam_time, dynam_result);



  
}
