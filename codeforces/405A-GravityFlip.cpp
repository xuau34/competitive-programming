#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, arr[105];
  scanf("%d", &N);
  for(i = 0; i < N; i++) scanf("%d", arr + i);
  sort(arr, arr+i);
  for(i = 0; i < N; i++){
    printf("%d", arr[i]);
    if(i != N - 1) printf(" ");
  }
  printf("\n");
}
