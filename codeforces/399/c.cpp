#include <bits/stdc++.h>
using namespace std;
int T, N, K, X, arr[100005];

void ini(void){
  int i, j;
  scanf("%d %d %d", &N, &K, &X);
  for(i = 0; i < N; i++){
    scanf("%d", arr + i);
  }
}

void sol(void){
  int i, j, k;
  if(K & 1) j = (99 < K)? 99: K;
  else j = (100 < K)? 100: K;
  for(i = 1; i <= j; i++){
    sort(arr, arr + N);
    for(k = 0; k < N; k += 2){
      arr[k] ^= X;
    }
    for(k = 0; k < N; k++) printf("%d ", arr[k]);
    printf("\n");
  }
  sort(arr, arr + N);
  printf("%d %d\n", arr[N - 1], arr[0]);
}

int main(void){
  int i, j;

  ini();

  sol();

}
