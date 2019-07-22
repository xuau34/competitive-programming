#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long dp[100005];
const int mod = 1e9 + 7;
void ini(void){
  scanf("%d%d", &T, &N);
  dp[0] = 1;
  for(int i = 0; i < 1e5; ++i){
    if(i + N <= 1e5) dp[i + N] = (dp[i + N] + dp[i]) % mod;
    dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
    dp[i] = (dp[i] + dp[i - 1]) % mod;
  }
  dp[(int)1e5] = (dp[(int)1e5] + dp[(int)1e5 - 1]) % mod;
}

void sol(void){
  int x, y, ans;
  while(T--){
    scanf("%d%d", &x, &y);
    ans = dp[y] - dp[x - 1];
    if(ans < 0) ans += mod; //not <= but < because % mod
    //so if ans is equal to mod, it should be %= mod, which is eqaul to 0.
    printf("%d\n", ans);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
