#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, dp[(int)1e6+10][2];

void ini(void){
  memset(dp, 127, sizeof(dp));
  dp[0][0] = 0;
  scanf("%d", &N);
}

inline bool check(int x){
  while(x){
    int i = x % 10;
    if(i != 0 && i != 1) return true;
    x /= 10;
  }
  return false;
}

void sol(void){
  for(int i = 1; i <= N; ++i){
    if( check(i) ) continue;
    //printf("\ni = %d\n", i);
    for(int j = 0; j + i <= N; ++j){
      if( dp[j + i][0] > dp[j][0] + 1 ){
        dp[j + i][0] = dp[j][0] + 1;
        dp[j + i][1] = j;
        //printf("dp[%d] = (%d, %d)\n", j + i, dp[j + i][0], dp[j + i][1]);
      }
    }
  }
  printf("%d\n", dp[N][0]);
  for(int i = dp[N][1], j = N; i < j; j = i, i = dp[i][1]) printf("%d ", j - i);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
