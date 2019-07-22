#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[1005], ar[2005], dp[1005][2005];
bool v[2][2005][2005];

void ini(void){
  scanf("%d%d%d", &N, &M, &Q);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
  for(int i = 0; i < M; ++i) scanf("%d", ar + i);
  T = abs( arr[0] - T );
  for(int j = 0; j < M; ++j){
    dp[0][j] = abs( arr[0] - ar[j] ) + T;
  }
}

void sol(void){
  int k, mi, ans = 0;
  for(int i = 1; i < N; ++i){
    T = abs( arr[i] - T );
    for(int j = 0; j < M; ++j){
      for(k = mi = 0; k < M; ++k){
        if(k == j || v[0][k][j]) continue;
        if(!mi || dp[i - 1][k] < dp[i - 1][mi]) mi = k;
      }
      dp[i][j] = dp[i - 1][mi] + abs( arr[i] - arr[j] ) + T;
      v[1][k][j] = 1;
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
