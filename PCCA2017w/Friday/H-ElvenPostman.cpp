#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[1005];

int main(void){
  int i, j, temp;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for(i = 0; i < N; i++) scanf("%d", arr + i);
    scanf("%d", &Q);
    while(Q--){
      scanf("%d", &j);
      i = 0;
      while(arr[i] != j){
        if(arr[i] > j){
          printf("E");
          i++;
        }else{
          printf("W");
          temp = arr[i];
          while(arr[i] <= temp && i < N) i++;
        }
      }
      printf("\n");
    }
  }
  return 0;
}
