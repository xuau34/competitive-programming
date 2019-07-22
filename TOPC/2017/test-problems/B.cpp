#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[30], dp[30][2];

void ini(void){
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
}

void ans(const int& x){
  if(dp[x][0] >= 0){
    ans(dp[x][0]);
    printf(" ");
  }
  printf("%d", arr[x]);
}

void sol(void){
  for(int i = M = 0; i < N; ++i){
    dp[i][1] = max(dp[i][1], 1);
    for(int j = i + 1; j < N; ++j){
      if(arr[j] > arr[i] && dp[j][1] < dp[i][1] + 1){
        dp[j][1] = dp[i][1] + 1, dp[j][0] = i;
        if(dp[j][1] > dp[M][1]) M = j;
      }
    }
  }
}

int main(void){

  while(scanf("%d", &N) == 1){
    ini();
    sol();
    ans(M);
    printf("\n");
  }
}
