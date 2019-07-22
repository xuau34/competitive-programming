#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long dp[33];

long long sol(int n){
  if(dp[n] > 0) return dp[n];
  long long ret = 0;
  for(int i = 1; i < n; ++i){
    ret += sol(i) * sol(n - i);
  }
  return dp[n] = ret;
}

void ini(void){
  scanf("%d", &N);
  dp[1] = 1;
  printf("%lld\n", sol(N + 1));
  //for(int i = 1; i <= N; ++i) printf("%lld ", sol(i));
  //printf("\n");
}


int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    ini();
  }
}
