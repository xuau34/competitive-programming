/*
  爆long long 
 */
#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d%d", &N, &M, &Q);
}

void sol(void){
  const int mod = 1e9 + 7;
  long long dp[105][2], temp[105][2], ans = 0;
  memset(dp, 0, sizeof(dp));
  memset(temp, 0, sizeof(temp));
  dp[0][0] = 1;
  for(int x = 0; x <= N; ++x){
    for(int i = x; i < N; ++i){
      for(int j = 1; j <= M && i + j <= N; ++j){
        if(j >= Q) temp[i + j][1] += dp[i][0] + dp[i][1];
        else temp[i + j][0] += dp[i][0], temp[i + j][1] += dp[i][1];
        temp[i + j][0] %= mod;
        temp[i + j][1] %= mod; 
        //printf("temp[%d] = (%d, %d)\n", i + j, temp[i + j][0], temp[i + j][1]);
      }
    }
    memcpy(dp, temp, sizeof(dp));
    memset(temp, 0, sizeof(temp));
    //printf("\n");
    //for(int i = 0; i <= N; ++i) printf("(%d,%d) ", dp[i][0], dp[i][1]);
    //printf("\n");
    ans += dp[N][1];
    ans %= mod;
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
