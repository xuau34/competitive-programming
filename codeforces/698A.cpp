#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, dp[105][2];

void ini(void){
  memset(dp, 127, sizeof(dp));
  for(int i = 0; i < 5; ++i) dp[i][0] = dp[i][1] = 0; 
  scanf("%d", &N);
}

void sol(void){
  for(int i = 5, x, y; i < N + 5; ++i){
    scanf("%d", &x), y = min(dp[i - 2][0], dp[i - 2][1]) + 1;
    dp[i][0] = min( dp[i - 1][1], y) + ((x < 2)? 1: 0);
    dp[i][1] = min( dp[i - 1][0], y) + ((x == 0 || x == 2)? 1: 0);
    //printf("(%d, %d)\n", dp[i][0], dp[i][1]);
  }
  printf("%d\n", min(dp[N + 4][0], dp[N + 4][1]));
}

int main(void){
  int i, j;

  ini();

  sol();

}
