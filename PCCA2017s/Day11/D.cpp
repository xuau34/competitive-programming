#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long dp[100005][2];
vector< pair<int, pair<int, int> > > vii[100005];
priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater<pair<long long, int> > > que;
bool v[100005], e[100005];
void ini(void){
  scanf("%d%d%d", &N, &M, &Q);
  int x, y, z;
  for(int i = 0; i < M; ++i){
    scanf("%d%d%d", &x, &y, &z);
    vii[x].push_back( make_pair(y, make_pair( i, z ) ) );
    vii[y].push_back( make_pair(x, make_pair( i, z ) ) );
  }
  for(int i = 0; i < Q; ++i){
    scanf("%d%d", &x, &y);
    vii[1].push_back( make_pair(x, make_pair( i + M, y ) ) );
    vii[x].push_back( make_pair(1, make_pair( i + M, y ) ) );
  }
  for(int i = 1; i <= N; ++i) dp[i][0] = 1e18;
  dp[1][0] = 0;
}

void sol(void){
  int x, ans = 0;
  que.push( make_pair(0, 1) );
  while(!que.empty()){
    x = que.top().second; que.pop();

    if( v[ x ] ) continue;
    v[ x ] = 1;
    
    //printf("dp[%d] = (%d, %d)\n", x, dp[x][0], dp[x][1]);

    for(int i = 0, j = vii[x].size(); i < j; ++i){
      if(!v[ vii[x][i].first ] && ( dp[ vii[x][i].first ][0] > dp[ x ][0] + vii[x][i].second.second ||
        (dp[ vii[x][i].first ][0] == dp[x][0] + vii[x][i].second.second && dp[ vii[x][i].first ][1] >= M &&
         vii[x][i].second.first < M)) ){
        que.push( make_pair( (dp[ vii[x][i].first ][0] = dp[x][0] + vii[x][i].second.second), vii[x][i].first ) ); 
        dp[ vii[x][i].first ][1] = vii[x][i].second.first;
      }
    }
  }
  for(pair<int, pair<int, int> > piii: vii[1])
    if( v[ piii.first ] && dp[ piii.first ][1] >= M ) ++ans, v[ piii.first ] = 0;
  printf("%d\n", Q - ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
