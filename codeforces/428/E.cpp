#include <bits/stdc++.h>
using namespace std;
const int C = 20;
int T, N, M, Q, dp[1 << C];
long long adj[40];

int ini(void){
  for(int i = 0; i < N; ++i) for(int j = 0, x; j < N; ++j)
    scanf("%d", &x), adj[i] |= (long long)(x || i == j) << j;
  for(int i = 1; i < (1 << max(0, N - C)); ++i){
    int x = i;
    for(int j = 0; j < C; ++j) if( (i >> j) & 1 )
      x &= adj[j + C] >> C;
    if(x == i) dp[i] = __builtin_popcount(i);
  }
  for(int i = 1; i < (1 << max(0, N - C)); ++i) for(int j = 0; j < C; ++j)
    if((i >> j) & 1) dp[i] = max(dp[i], dp[i ^ (1 << j)]);
}

void sol(void){
  int ans = 0;
  for(int i = 0; i < (1 << min(C, N)); ++i){
    int x = i, y = (1 << max(0, N - C)) - 1;
    for(int j = 0; j < min(C, N); ++j) if((i >> j) & 1)
      x &= adj[j] & ((1 << C) - 1), y &= adj[j] >> C;
    if(x != i) continue;
    ans = max(ans, __builtin_popcount(i) + dp[y]);
  }
  long double x = (long double) M / ans;
  //cout << x * x * ans * (ans - 1) / 2;
  printf("%.8Lf\n", x * x * ans * (ans - 1) / 2);

}

int main(void){

  scanf("%d%d", &N, &M);

  ini();

  sol();

}
