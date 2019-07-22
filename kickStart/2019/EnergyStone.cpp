#include "bits/stdc++.h"
using namespace std;
int S[105], E[105], L[105], N;
int dp[10100][105];

int solve( pair<double, int> indexes[], int T, int i){
  if(T > 10095 || i >= N) return 0;
  int idx = indexes[i].second;
  if(dp[T][i] >= 0) return dp[T][i];
  return dp[T][i] = max( solve(indexes, T + S[idx], i+1) + max(0,E[idx] - T * L[idx]),
                         solve(indexes, T, i+1) );
}

int main(void){
  int T;
  scanf("%d", &T);
  for(int Case = 1; Case <= T; ++Case){
    scanf("%d", &N);
    pair<double, int> indexes[N]; 
    for(int i = 0; i < N; ++i){
      scanf("%d%d%d", S + i, E + i, L + i);
      if(L[i] > 0) indexes[i].first = ((double) S[i])/L[i];
      else indexes[i].first = 500;
      indexes[i].second = i;
    }
    sort(indexes, indexes + N);
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 0; i < N; ++i){
      ans = max(ans, solve(indexes, 0, i));
    }
    printf("Case #%d: %d\n", Case, ans);
  }
}
