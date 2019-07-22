#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, color[200005];
bool visit[200005];
pair<int, int> edges[200005];
vector< pair<int, int> > nodeTo[ 200005 ];

bool dfs( int x, int c ){
  if( color[x] && color[x] != c ) return true;
  color[x] = c;
  bool ret = false;
  int C = (c == 1)? 2: 1;
  for( auto pii: nodeTo[x] ){
    if( !visit[ pii.second ] ){
      visit[ pii.second ] = 1;
      ret |= dfs( pii.first, C );
      if( ret ) return true;
    }
  }

  return ret;
}

void ini(void){
  memset(color, 0, sizeof(color));
  memset(visit, 0, sizeof(visit));
  cin >> N >> M;
  for(int i = 0, s, t; i < M; ++i){
    cin >> s >> t;
    edges[i] = make_pair(s, t);
    nodeTo[s].push_back( make_pair(t, i) );
    nodeTo[t].push_back( make_pair(s, i) );
  }
}

void sol(void){
  if( dfs(1, 1) ){
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for( int i = 0, x; i < M; ++i ){
    x = edges[i].first;
    cout << (color[ x ] == 1);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
