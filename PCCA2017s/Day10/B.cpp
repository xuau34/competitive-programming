#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long dp[100005][2];
vector<pair<int, int> > v[100005];
bool visit[100005];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pii;
void ini(void){
  scanf("%d%d", &N, &M);
  int x, y, z;
  for(int i = 1; i <= N; ++i) dp[i][0] = 300000000000LL;
  dp[1][0] = 0; dp[N][1] = N;
  for(int i = 0; i < M; ++i){
    scanf("%d%d%d",  &x, &y, &z);
    v[x].push_back( make_pair(y, z) );
    v[y].push_back( make_pair(x, z) );
  }
}

void dfs( void ){
  int x;
  while(!pii.empty()){
    x = pii.top().second;
    pii.pop();
    if(visit[x]) continue;
    visit[x] = 1;
    for(int i = 0, j = v[x].size(); i < j; ++i){
      if( dp[v[x][i].first ][0] > dp[x][0] + v[x][i].second){
        dp[ v[x][i].first ][0] = dp[x][0] + v[x][i].second;
        dp[ v[x][i].first ][1] = x;
        pii.push( make_pair( dp[ v[x][i].first ][0], v[x][i].first ) );
      }
    }
  }
}

void sol(void){
  pii.push( make_pair(0, 1) );
  dfs();
  vector<int> ans;
  if(dp[N][1] == N) printf("-1\n");
  else{
    for(int i = N; i > 1; i = dp[i][1]) ans.push_back(i);
    printf("1 ");
    for(int i = ans.size() - 1; i >= 0; --i) printf("%d ", ans[i]);
    printf("\n");
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
