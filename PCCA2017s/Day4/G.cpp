#include <bits/stdc++.h>
using namespace std;
int N, M, S, T, Q, arr[105][105];
int bt[105];
//vector< pair<int, int> > v[105];
queue<int> que;
void ini(void){
  int x, y, z;
  scanf("%d %d %d", &S, &T, &Q);
  for(int i = 0; i < Q; ++i){
    scanf("%d %d %d", &x, &y, &z);
    //v[x].push_back( make_pair(y, z) );
    //v[y].push_back( make_pair(x, z) );
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
  while(scanf("%d", &N) && N){
    printf("Network %d\n", ++i);
    ini();
    sol();
    memset(arr, 0, sizeof(arr));
  }
}
