#include <bits/stdc++.h>
using namespace std;
int T, N, K, M, Q, dp[30005][2];
bool v[30005];

int main(void){
  int i, j, p, b, c, x, ans;
  scanf("%d", &T);
  while(T--){
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &N, &K, &x);
    for(i = ans = 0; i < N; i++){
      memset(v, 0, sizeof(v));
      scanf("%d %d %d", &p, &b, &c);
      //dp[K * p][0] = c - K;
      //dp[K * p][1] = (dp[K * p][1] < b * K)? b * K: dp[K * p][1];
      for(j = 0, dp[0][0] = c; j <= x; j++){
        if(dp[j][0]){
          if(!v[j]){
            dp[j + p * K][0] = c - K;
            dp[j + p * K][1] = (dp[j + p * K][1] < dp[j][1] + b * K)? dp[j][1] + b * K: dp[j + p * K][1];
            v[j + p * K] = 1;
          }else{
            dp[j + p][0] = dp[j][0] - 1;
            dp[j + p][1] = (dp[j + p][1] < dp[j][1] + b)? dp[j][1] + b: dp[j + p][1];
            v[j + p] = 1;
          }
        }
        ans = (dp[j][1] > ans)? dp[j][1]: ans;
      }
    }
    for(i = 0; i <= x; i++) cout<<dp[i][0]<<","<<dp[i][1]<<" ";
    cout<<endl;
    printf("%d\n", ans);
  }
}
