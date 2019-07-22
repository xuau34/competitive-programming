#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, ans, arr[1005][1005], prel[1005][1005], prer[1005][1005];

void ini(void){
  scanf("%d" ,&N);
  for(int i = 0; i < 1005; ++i) for(int j = 0; j < 1005; ++j) prel[i][j] = prer[i][j] = -10000000;
  ans = -10000000;
  for(int i = 1; i <= N; ++i){
    for(int j = 1; j <= N; ++j){
      scanf("%d", arr[i] + j);
      prel[i][j] = prer[i][j] = arr[i][j];
    }
  }
}

void sol(void){
  for(int i = 2; i <= N; ++i){
    for(int j = 2; j < N; ++j){
      ans = max(ans, prel[i - 1][j - 1] + arr[i][j] + prer[i - 1][j + 1]);
      prel[i][j] = max( prel[i][j], prel[i][j] + prel[i - 1][j - 1]);
      prer[i][j] = max( prer[i][j], prer[i][j] + prer[i - 1][j + 1]);
    }
  }
  /*
  for(int i = 1; i <= N; ++i){
    for(int j = 1; j <= N; ++j){
      printf("(%d,%d) ", prel[i][j], prer[i][j]);
    }
    printf("\n");
  }*/
  printf("%d\n", ans);
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
