#include "bits/stdc++.h"
using namespace std;
int main( void ){
  int N, M;
  while( cin >> N >> M ){
    bool visit[ N ][ M ];
    memset( visit, 0, sizeof( visit ) );
    cout << N << " " << M << "!!!!!!!!!!!!!!\n";
    for( int z = 0, i, j, x, y; z < N * M; ++z){
      cin >> x >> y;
      x -=1, y -= 1;
      if( x < 0 || y < 0 || x >= N || y >= M|| visit[x][y] || (z && (x == i || y == j || x + y == i + j || x - y == i - j)) ){
        cout << "False!" << endl;
        return -1;
      }
      cout << x << " " << y << endl;
      visit[x][y] = 1;
      i = x, j = y;
    }
    for( int i = 0; i < N; ++i){
      for( int j = 0; j < M; ++j ){
        if( !visit[i][j] ){
        cout << "False!" << endl;
        return -1;
        }
      }
    }
  }
}
