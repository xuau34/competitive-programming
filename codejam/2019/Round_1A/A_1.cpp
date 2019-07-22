#include <bits/stdc++.h>
#define MAX_ 55
using namespace std;
int T, N, M, Q, needle[ MAX_ ][2];
bool visit[ MAX_ ][ MAX_ ], tran;
vector< pair<int, int> > ans;

void pre(void){ //Input
  cin >> N >> M;
  if( N > M ){
    swap( N, M );
    tran = true;
  }else tran = false;
}

void ini(void){ //Initialization
  memset(visit, 0, sizeof(visit) );
  Q = N * M;
  if( ans.size() < N * M ) ans.resize( N * M );

  // needle[i]: keeping where next step should start in i-th row.
  // even - from the boundary
  // odd  - from the center
  for( int i = 0; i < N; ++i ){
    if( i & 1 ){
      needle[i][0] = M >> 1;
      needle[i][1] = needle[i][0] + 1;
    }else {
      needle[i][0] = 0, needle[i][1] = M - 1;
    }
  }
}

inline bool valid( int x, int y, int i, int j ){  //check if this move, from x,y to i,j, is valid.
  return i >= 0 && j >= 0 && i < N && j < M && !visit[i][j] && !( x == i || y == j || x + y == i + j || x - y == i - j );
}

bool sol( int x, int y, int len ){  //recursive til one solution found (returning true).

  //One solution found
  if( len == Q ){
    ans[ --Q ] = make_pair( x + 1, y + 1 );
    return true;
  }

  //Step-in (x,y)
  visit[x][y] = true;

  //keep track if there is a solution
  bool clear = false;
  
  //find the next possible steps => (i,a), (i,b)
  int i = (x + 1) % N, a = needle[i][0], b = needle[i][1], bias = (i & 1)? -1: 1;
  while( a >= 0 && a < M && (visit[i][a] || !valid(x, y, i, a) ) ) a += bias;
  while( b >= 0 && b < M && (visit[i][b] || !valid(x, y, i, b) ) ) b -= bias;

  //recursive called. rand() could help speed up.
  //if( rand() < RAND_MAX >> 1 ) swap(a, b);
  if( valid(x, y, i, a ) ) clear |= sol(i, a, len + 1);
  if( !clear && a != b && valid(x, y, i, b ) ) clear |= sol(i, b, len + 1);

  visit[x][y] = false;
  //Step-out (x,)

  if( !clear ) return false;

  //if there's solution => then include this coordinate.
  ans[ --Q ] = make_pair( x + 1, y + 1 );
  return true;
}

int main(void){
  cin >> T;
  for( int Case = 1; Case <= T; ++Case ){
    pre();  //Input
    ini();  //Initialization

    //Output
    if( N > 1 && M > 1 && sol(0, 0, 1) ){
      printf("Case #%d: POSSIBLE\n", Case );

      //tran = whether N,M has been swapped => a little speed up for this method. 
      if(tran) {
        for( int i = 0; i < N * M; ++i ) printf( "%d %d\n", ans[i].second, ans[i].first );
      }else{
        for( int i = 0; i < N * M; ++i ) printf( "%d %d\n", ans[i].first, ans[i].second );
      }

    }else printf("Case #%d: IMPOSSIBLE\n", Case );
  }
  return 0;
}
