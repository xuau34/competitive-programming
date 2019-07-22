#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[105][105], dp[105][105], w[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string str;
priority_queue< pair< int, pair<int, int> > > que;
void ini(void){
  cin >> str >> N >> M;
  cout << str;
  memset(dp, -1, sizeof(dp));
  for(int i = 1; i <= N; ++i){
    for(int j = 1; j <= M; ++j){
      scanf("%d", arr[i] + j);
      que.push( make_pair( arr[i][j], make_pair(i, j) ) );
    }
  }
}

int fil(int x, int y){
  if(dp[x][y] >= 0) return dp[x][y];
  int ret = 0;
  for(int i = 0; i < 4; ++i){
    if( arr[x][y] > arr[ x + w[i][0] ][ y + w[i][1] ] ){
      //dp[ x + w[i][0] ][ y + w[i][1] ];
      //printf("(%d, %d) -> (%d, %d)\n", x, y, x + w[i][0], y + w[i][1]);
      ret = max( ret, fil( x + w[i][0], y + w[i][1] ) );
    }
  }
  //printf("(%d, %d) = %d\n", x, y, ret + 1);
  return dp[ x ][ y ] = ret + 1;
}

void sol(void){
  int X, Y, ans = 0;
  while( !que.empty() ){
    X = que.top().second.first, Y = que.top().second.second;
    //printf("que.top = (%d, (%d, %d))\n", que.top().first, X, Y);
    que.pop();
    if( dp[X][Y] >= 0 ) continue;
    ans = max( ans, fil(X, Y) );
    /*
    for(int i = 1; i <= N; ++i){
      for(int j = 1; j <= M; ++j){
        for(int k = 0; k < 4; ++k){
          dp[i][j] = 
        }
      }
    }
    */
  }
  printf(": %d\n", ans);
}

int main(void){
  int i, j;
  for(int i = 0; i < 105; ++i) for(int j = 0; j < 105; ++j) arr[i][j] = 1000;
  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
