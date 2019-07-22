#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, cnt[100005];
long long dp[100005], ans;
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", &Q);
    ++cnt[Q];
    M = max(M, Q);
  }
}

void sol(void){
  ans = dp[1] = cnt[1];
  for(long long i = 2; i <= M; ++i){  //i should be long long
    dp[i] = cnt[i] * i + max( dp[i - 2], dp[i - 3] );
    ans = max(ans, dp[i]);
  }
  printf("%lld\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
