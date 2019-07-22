#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool visit[ 25 ][ 25 ];
vector< pair<int, int> > ans;
void ini(void){
  cin >> N >> M;
  memset(visit, 0, sizeof(visit) );
  Q = N * M;
  if( ans.size() < Q ) ans.resize( Q );

}

bool sol( int x, int y, int len ){
  visit[x][y] = 1;
  if( len == N * M ){
      ans[ --Q ] = make_pair( x + 1, y + 1 );
      return true;
  }
  for(int i = 0; i < N; ++i ){
    for( int j = 0; j < M; ++j ){
      if( visit[i][j] || i == x || j == y || i - j == x - y ||  i + j == x + y ) continue;
      if( sol( i, j, len + 1 ) ){
        ans[ --Q ] = make_pair( x + 1, y + 1 );
        return true;
      }
    }
  }
  visit[x][y] = 0;
  return false;
}

int main(void){
  cin >> T;
  for( int Case = 1; Case <= T; ++Case ){
    ini();
    bool ret = false;
    for( int i = 0; i < N && !ret; ++i ){
      for( int j = 0; j < M && !ret; ++j ){
        ret |= sol( i, j, 1 );
      }
    }
    if( ret ){
      //printf("Case #%d: POSSIBLE\n", Case );
      //for( int i = 0; i < N * M; ++i ) printf( "%d %d\n", ans[i].first, ans[i].second );
    }else printf("%d %d\n", N, M);//printf("Case #%d: IMPOSSIBLE\n", Case );
  }
  return 0;
}

