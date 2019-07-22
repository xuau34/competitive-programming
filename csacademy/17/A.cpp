#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[51][51], ways[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };


inline bool valid(int i, int j){
  return i > -1 && j > -1 && i < N && j < M;
}

void flow( int x, int y, int dis){
  arr[x][y] = dis++;
  for( int way = 0, i, j; way < 8; ++way ){
    i = x + ways[ way ][0], j = y + ways[ way ][1];
    if( valid( i, j ) && (arr[i][j] < 0 || arr[i][j] > dis) ) flow(i, j, dis);
  }
}

void ini(void){
  memset(arr, -1, sizeof(arr));
  scanf("%d%d", &N, &M);
  for( int i = 0; i < N; ++i ){
    for( int j = 0, k; j < M; ++j ){
      scanf("%d", &k);
      if(k){
        flow( i, j, 0 );
      }
    }
  }
}
int main(void){

  ini();

  int ans = arr[0][0];

  for(int i = 0; i < N; ++i){
    for( int j = 0; j < M; ++j ){
      if(arr[i][j] > ans) ans = arr[i][j];
    }
  }
  
  cout << ans << endl;

}
