#include <bits/stdc++.h>
using namespace std;
int n, v[255];
long long dp[255][255][255], prefix[255];
long long solve(int i, int j, int r){
  if(dp[i][j][r] != -1) return dp[i][j][r];
  int k;
  long long int a, b;
  for(k = i, a = b = (1<<30); k < r; k++) a = min(a, solve(i, r - 1, k));
  for(k = r + 1; k <= j; k++) b = min(b, solve(r + 1, j, k));
  if(a == (1<<30)) a = 0;
  if(b == (1<<30)) b = 0;
  dp[i][j][r] = a + b;
  //printf("dp[%d][%d][%d] = %lld => ", i, j, r, dp[i][j][r]);
  //for(k = i; k <= j; k++) if(k != r) dp[i][j][r] += v[k];
  dp[i][j][r] += (prefix[r - 1] - prefix[i - 1] + prefix[j] - prefix[r]);
  //printf("dp[%d][%d][%d] = %lld\n", i, j, r, dp[i][j][r]);
  return (dp[i][j][r]);
}
int main(void){
  int i;
  long long ans;
  while(~scanf("%d", &n)){
    for(i = 1; i <= n; i++) scanf("%d", v + i);
    memset(dp, -1, sizeof(dp));
    memset(prefix, 0, sizeof(prefix));
    sort(v, v + n);
    for(i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + v[i];
    for(i = 1, ans = (1<<30); i <= n; i++) ans = min(ans, solve(1, n, i));
    for(i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        for(int r = 1; r <= n; r++) printf("%lld ", dp[i][j][r]);
        cout<<endl;
      }
    }
    //if(ans > (1<<30) || ans < 0) cout<<"0"<<endl;
    cout<<ans<<endl;
  }
}
