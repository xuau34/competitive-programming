#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[(int)1e5+10][2], dp[(int)1e5+10][2];

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d%d", arr[i], arr[i] + 1);
  dp[0][0] = 1;
  if(arr[0][0] + arr[0][1] < arr[1][0]) dp[0][1] = 1;
  //printf("(%d, %d)\n", dp[0][0], dp[0][1]);
}

void sol(void){
  for(int i = 1; i < N - 1; ++i){
    int l = arr[i][0] - arr[i][1], r = arr[i][0] + arr[i][1];
    dp[i][0] = dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    if(l > arr[i - 1][0]) dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
    if(l > arr[i - 1][0] + arr[i - 1][1]) dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
    if(r < arr[i + 1][0]) ++dp[i][1];
    //printf("(%d, %d)\n", dp[i][0], dp[i][1]);
  }
  printf("%d\n", max(dp[N - 2][0], dp[N - 2][1]) + 1);
}

int main(void){
  int i, j;

  ini();

  sol();

}
