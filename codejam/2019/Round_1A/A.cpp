#include <bits/stdc++.h>
#define MAX_ 105
using namespace std;
int T, N, M, Q, needle[ MAX_ ][2];
bool visit[ MAX_ ][ MAX_ ], tran;
vector< pair<int, int> > ans;

void pre(void){
  cin >> N >> M;
  if( N > M ){
    swap( N, M );
    tran = true;
  }else tran = false;
}

void ini(void){
  memset(visit, 0, sizeof(visit) );
  Q = 0;
  if( ans.size() < N * M ) ans.resize( N * M );
  for( int i = 0; i < N; ++i ){
    if( i & 1 ){
      needle[i][0] = M >> 1;
      needle[i][1] = needle[i][0] + 1;
    }else {
      needle[i][0] = 0, needle[i][1] = M - 1;
    }
  }
}

inline bool valid( int x, int y, int i, int j ){
  return i >= 0 && j >= 0 && i < N && j < M && !visit[i][j] && !( x == i || y == j || x + y == i + j || x - y == i - j );
}

bool sol( void ){
  int x, y;
  bool begin = true;
  while( Q < N * M ){
    if( begin ){
      x = y = 0;
      begin = false;
      needle[x][0] = 1;
      //printf("%d %d from begin", x, y );
    }else{
      bool clear = false;
      for( int i = (x + 1) % N, j = 0, bias = (i & 1)? -1: 1; j < M ; ++j){
        //if( needle[i][0] == needle[i][1] || (needle[i][0] == -1 && needle[i][1] == M) ) return false;
        if( rand() < INT_MAX>>1 && valid(x, y, i, j * bias * -1 + needle[i][1]) ){
          x = i, y = j* bias * -1 + needle[i][1];
          //printf("%d %d from needle_%d = (%d, %d), j = %d", x, y, i, needle[i][0], needle[i][1], j);
          if(!j)needle[i][1] -= bias;
          clear = true;
          break;
        }else if( valid(x, y, i, j * bias + needle[i][0]) ){
          x = i, y = j* bias + needle[i][0];
          //printf("%d %d from needle_%d = (%d, %d), j = %d", x, y, i, needle[i][0], needle[i][1], j);
          if(!j)needle[i][0] += bias;
          clear = true;
          break;
        }else if( valid(x, y, i, j * bias * -1 + needle[i][1]) ){
          x = i, y = j* bias * -1 + needle[i][1];
          //printf("%d %d from needle_%d = (%d, %d), j = %d", x, y, i, needle[i][0], needle[i][1], j);
          if(!j)needle[i][1] -= bias;
          clear = true;
          break;
        }
      }
      if( !clear ) return 0;
    }
    ans[Q++] = make_pair( x+1, y+1 );
    visit[x][y] = 1;
    int bias = (x & 1)? -1: 1;
    while( needle[x][0] >= 0 && needle[x][0] < M && visit[x][ needle[x][0] ] ) needle[x][0] += bias;
    while( needle[x][1] >= 0 && needle[x][1] < M && visit[x][ needle[x][1] ] ) needle[x][1] -= bias;
    //printf(" => (%d, %d)\n", needle[x][0], needle[x][1]);
  }
  return true;
}

int main(void){
  srand( time(0) );
  cin >> T;
  for( int Case = 1; Case <= T; ++Case ){
    pre();
    bool pass = false;
    for( int i = 0; i < 20 && !pass; ++i ){
      ini();
      pass |= sol();
    }
    if( N > 1 && M > 1 && pass ){
      printf("Case #%d: POSSIBLE\n", Case );
      if(tran) {
      //cout << M << " " << N << endl;
        for( int i = 0; i < N * M; ++i ) printf( "%d %d\n", ans[i].second, ans[i].first );
      }else{
      //cout << N << " " << M << endl;
        for( int i = 0; i < N * M; ++i ) printf( "%d %d\n", ans[i].first, ans[i].second );
      }
    }/*else{
      if(tran) cout << M << " " << N << endl;
      else cout << N << " " << M << endl;
    }*/else printf("Case #%d: IMPOSSIBLE\n", Case );
  }
  return 0;
}
