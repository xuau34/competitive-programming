#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[1100], dp[1100][1100];

int main(void){
  int i, j, ans, MA, temp;
  scanf("%d", &T);
  while(T--){
    memset(dp, 0, sizeof(dp));
    memset(arr, 0, sizeof(arr));
    scanf("%d %d", &N, &M);
    for(i = 5, ans = temp = 0; i < N + 5; i++){
      scanf("%d", arr + i);
      ans += arr[i];
    }
    /*
    for(j = 1; j <= M; j++){
      for(i = 5; i < N + 5; i++){
        if(j > 1) dp[i][j] = dp[i - 1][j - 1] + arr[i] * 3;
        dp[i][j] = (dp[i][j] < dp[i - 2][j - 1] + arr[i])? dp[i - 2][j - 1] + arr[i] : dp[i][j];
        cout<<dp[i][j]<<" ";
      }
    }
    */
    for(j = 1; j <= M; j++){
      for(i = 3 + j, MA = 2; i < N + 5; i++){
        if(j > 1) dp[i][j] = dp[i - 1][j - 1] + arr[i] * 2 + arr[i + 1];
        dp[i][j] = (dp[i][j] < dp[MA][j - 1] + arr[i] + arr[i + 1])? dp[MA][j - 1] + arr[i] + arr[i + 1]:
          dp[i][j];
        MA = (dp[MA][j - 1] < dp[i - 1][j - 1])? i - 1: MA;
        //cout<<dp[i][j]<<":"<<MA<<" ";
        if(j == M) temp = (temp < dp[i][j])? dp[i][j]: temp;
      }
      //cout<<endl;
    }
    printf("%d\n", ans + temp);
  }
}
