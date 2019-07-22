#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cash, n, arr[15][2];
int dp[100005];
int main(void){
  int i, j, k;
  while(~scanf("%d", &cash)){
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d %d", arr[i], arr[i] + 1);
    memset(dp, -1, sizeof(dp));
    for(i = 0, dp[0] = 0; i < n; i++){
      for(j = 0; j <= cash; j++){
        if(dp[j] >= 0){
          dp[j] = arr[i][0];
        }else if(j - arr[i][1] >= 0 && dp[j - arr[i][1]] > 0){
          dp[j] = dp[j - arr[i][1]] - 1;
        }
      }
    }
    while(dp[cash] < 0) cash--;
    printf("%d\n", cash);
  }
}
