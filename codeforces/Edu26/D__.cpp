/*
  此借鑒一些較快的code。
  dp[取了多少][5的數量] = 2的數量
 */

#include <bits/stdc++.h>
using namespace std;
int T, N, M, dp[205][5005];

void ini(void){
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  scanf("%d%d", &N, &M);
}

void sol(void){
  for(int i = 0; i < N; ++i){
    long long x;
    scanf("%lld", &x);
    int a = 0, b = 0;
    while(!(x & 1)) ++a, x >>= 1;
    while(!(x % 5)) ++b, x /= 5;
    for(int k = min(i, M); k >= 0; --k)
      for(int j = 0; j < 5005; ++j) 
        if(dp[k][j] >= 0)
          dp[k + 1][j + b] = max(dp[k + 1][j + b], dp[k][j] + a);
  }
  for(int i = 0; i < 5005; ++i) T = max(T, min(dp[M][i], i));
  printf("%d\n", T);
}

int main(void){
  int i, j;

  ini();

  sol();

}
