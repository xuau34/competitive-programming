#include <bits/stdc++.h>
using namespace std;
int dp[50][50][50][50], t, m, n, r, c;
int divide(int r, int c, int R, int C){
  if(dp[r][c][R][C] != -1) return dp[r][c][R][C];
  if(R == 1 && C == 1) return dp[r][c][R][C] = 0;
  int i, ans = 1;
  for(i = 1; i <= r && ans; i++) ans &= divide(r - i, c, R - i, C);
  for(i = r + 1; i < R && ans; i++) ans &= divide(r, c, i, C);
  for(i = 1; i <= c && ans; i++) ans &= divide(r, c - i, R, C - i);
  for(i = c + 1; i < C && ans; i++) ans &= divide(r, c, R, i);
  if(!ans) return dp[r][c][R][C] = 1;
  else return dp[r][c][R][C] = 0;
}
int main(void){
  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d %d", &m, &n, &r, &c);
    memset(dp, -1, sizeof(dp));
    if(divide(r, c, m, n)) printf("Gretel\n");
    else printf("Hansel\n");
  }
}
