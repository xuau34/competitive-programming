#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, ans[2005];
char mat[1005][1005];
bool par[2005], visit[2005];
vector<ll> nodes[2005];

void ini( void ){
  cin >> N >> M;
  memset( par, 0, sizeof(par) );
  memset( visit, 0, sizeof(visit) );
  for( int i = 0; i < N; ++i ){
    for( int j = 0; j < M; ++j ){
      cin >> mat[i][j];
    }
  }

  for( int i = 0; i < N; ++i ){
    for( int j = 0; j < M; ++j ){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }

}

void label( int x, int v ){
  if( visit[x] ) return;
  visit[x] = 1;
  ans[ x ] = v;
  for( int i = 0; i < nodes[x].size; ++i ){
    label( nodes[x][i], v + 1);
  }
}

bool check( void ){
  for( int i = 0; i < N; ++i ){
    for( int j = 0; j < M; ++j ){
      switch(mat[i][j]){
        case '<':
          if( ans[i] >= ans[j] ) return false;
          break;
        case '=':
          if( ans[i] == ans[j] ) return false;
          break;
        case '>':
          if( ans[i] <= ans[j] ) return false;
          break;
      }
    }
  }
  return true;
}

void sol( void ){
  for( int i = 0; i < N; ++i ){
    for( int j = 0; j < M; ++j ){
      switch(mat[i][j]){
        case '<':
          nodes[i].push_back( N + j );
          par[ N + j ] = 1;
          break;
        case '>':
          nodes[j].push_back( i );
          par[ i ] = 1;
          break;
      }
    }
  }
  for( int i = 0, l = N + M; i < l; ++i){
    if( !par[i] ) label( i, 1 );
  }
  if( !check() ) cout << "No" << endl;
  else{
    cout << "Yes" << endl;
    for( int i = 0; i < N; ++i ) cout << ans[i] << " ";
    cout << endl;
    for( int i = 0; i < M; ++i ) cout << ans[i + N] << " ";
    cout << endl;
  }
}

int main(void){
  ios::sync_with_stdio(false);
  ini();
  sol();
}
