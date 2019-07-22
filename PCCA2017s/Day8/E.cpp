#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[305], mat[305][305];

void ini(void){
  char c[305];
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) scanf("%d", arr + i);
  for(int i = 1; i <= N; ++i){
    scanf("%s", c);
    for(int j = 1; j <= N; ++j) mat[i][j] = c[j - 1] - '0';
  }
}

void sol(void){
  for(int k = 1; k <= 10000; ++k){
    for(int i = 1; i <= N; ++i){
      for(int j = 1; j <= N; ++j) if( i < j && mat[i][j] && arr[i] > arr[j]){
        swap(arr[i], arr[j]);
        //printf("(%d, %d) swap(%d, %d)\n", i, j, arr[i], arr[j]);
      }
    }
  }
  for(int i = 1; i <= N; ++i) printf("%d ", arr[i]);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
