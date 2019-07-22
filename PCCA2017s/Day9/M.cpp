#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
vector< pair<int, int> > arr[105];
bool v[105];
int dp[105];
void ini(void){
  int a, b, c;
  for(int i = 0; i < M; ++i){
    scanf("%d%d%d", &a, &b, &c);
    arr[a].push_back( make_pair(b, c) );
    arr[b].push_back( make_pair(a, c) );
  }
  for(int i = 2; i <= N; ++i) dp[i] = 2147483640;
  dp[1] = 0;
}

void dfs(int x){
  v[x] = 1;
  for(int i = 0, j = arr[x].size(); i < j; ++i)
    dp[ arr[x][i].first ] = min( dp[ arr[x][i].first ], dp[x] + arr[x][i].second );
  for(int i = 0, j = arr[x].size(); i < j; ++i)
    if(!v[ arr[x][i].first ]) dfs( arr[x][i].first );
}

void sol(void){
  dfs(1);
  printf("%d\n", dp[N]);
  memset(v, 0, sizeof(v));
  for(int i = 1; i <= N; ++i) arr[i].clear();
}

int main(void){
  int i, j;
  while( scanf("%d%d", &N, &M) && N + M){

  ini();

  sol();
  }
}
