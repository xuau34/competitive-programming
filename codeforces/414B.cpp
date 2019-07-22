#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long dp[2005][2005];
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; ++i) dp[1][i] = 1;
}

void sol(void){
  const int mod = 1e9 + 7;
  for(int i = 1; i < M; ++i){
    for(int j = 1; j <= N; ++j){
      for(int k = j; k <= N; k += j){
        dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
      }
    }
  }
  long long ans = 0;
  for(int i = 1; i <= N; ++i) ans = (ans + dp[M][i]) % mod;
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
