#include <bits/stdc++.h>
using namespace std;
int n, v[255], dp[255][255];
long long solve(int i, int j, int r, int l){
  //if(r < 1) return 0;
      //cout<<i<<","<<j<<" ";
  long long a = 0, b = 0;
  if(r > 1 && dp[i][r - 1] != -1) a = solve(i, r - 1, dp[i][r - 1], l + 1);
  //else for(k = i, a = b = (1<<30); k < r; k++) a = min(a, solve(i, r - 1, k, l + 1));
  if(r + 1 <= n && dp[r + 1][j] != -1) b = solve(r + 1, j, dp[r + 1][j], l + 1);
  //else for(k = r + 1; k <= j; k++) b = min(b, solve(r + 1, j, k, l + 1));
  //getchar();
  //cout<<i<<","<<j<<","<<r<<","<<l<<":"<<(a + b + v[r] * l)<<endl;
  return (a + b + v[r] * l);
}
void Dp(void){
  long long mmmmmmmmm, temp;
  for(int j = 2; j <= n; j++){
    for(int i = 1; i + j - 1 <= n; i++){
      //cout<<i<<","<<i + j - 1<<","
      //cout<<i<<","<<i + j - 1<<":"<<dp[i][i + j - 2]<<" -> "<<solve(i, i + j - 1, dp[i][i+j-2], 0)<<endl;
      dp[i][i + j - 1] = dp[i][i + j - 2];
      mmmmmmmmm = solve(i, i + j - 1, dp[i][i + j - 1], 0);
      for(int k = dp[i][i + j - 2] + 1; k <= dp[i + 1][i + j - 1]; k++){
        if(mmmmmmmmm > (temp = solve(i, i + j - 1, k, 0))){
          dp[i][i + j - 1] = k;
          mmmmmmmmm = temp;
        }
      }
    }
    //cout<<endl;
  }
}
int main(void){
  int i;
  while(~scanf("%d", &n)){
    for(i = 1; i <= n; i++) scanf("%d", v + i);
    memset(dp, -1, sizeof(dp));
    for(i = 1; i <= n; i++) dp[i][i] = i;
    Dp();
    /*for(i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        printf("%d ", dp[i][j]);
      }
        cout<<endl;
    }*/
    //if(ans > (1<<30) || ans < 0) cout<<"0"<<endl;
    cout<<solve(1, n, dp[1][n], 0)<<endl;
  }
}
