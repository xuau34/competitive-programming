#include <bits/stdc++.h>
using namespace std;
int N, M, S, T, Q, arr[100005][15];
int bt[105];
queue<int> que;
void ini(void){
  int x, y, z;
  memset(arr, 0, sizeof(arr));
  for(int i = 1; i <= M; ++i){
    for(int j = 1; j <= N; ++j){
      scanf("%d", &x);
      arr[i][j] = x;
    }
  }
  for(int i = 0; i < Q; ++i){
    scanf("%d %d %d", &x, &y, &z);
    arr[x][y] = (arr[y][x] += z);
  }
}

bool arg( void ){
  memset(bt, 0, sizeof(bt));
  bt[S] = -1;
  que.push( S );
  int x;
  while( !que.empty() ){
    x = que.front();
    que.pop();
    for(int i = 1; i <= N; ++i){
      if( arr[x][i] && !bt[i] ){
        bt[i] = x;
        if( i == T ) return 1; 
        que.push( i );
      }
    }
  }
  return 0;
}

void reduce( int red ){
  int x = T;
  while( bt[x] > 0 ){
    arr[ x ][ bt[x] ] += red;
    arr[ bt[x] ][ x ] -= red;
    x = bt[ x ];
  }
}

int flow(){
  int ret = 1000000;
  int x = T;
  while( bt[x] > 0 ){
    ret = min( ret, arr[ bt[x] ][ x ] );
    x = bt[ x ];
  }
  return ret;
}

void sol(void){
  long long ans = 0, temp;
  while( arg() ){
    temp = flow();
    ans += temp;
    reduce( temp );
    while(!que.empty()) que.pop();
  }
  printf("The bandwidth is %lld.\n\n", ans);
}

int main(void){
  int i = 0, j;
  while(scanf("%d %d", &N, &M) == 2){
    ini();
    sol();
    memset(arr, 0, sizeof(arr));
  }
}
