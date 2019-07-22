#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;
int T, N, M, Q, arr[500005], p[500005][2], ans[500005];
vector< pair<int, int> > node[500005];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
  memset(p, -1, sizeof(p));
  p[0][0] = -1, p[0][1] = 0;
  memset(ans, 0, sizeof(ans));
  for(int i = 1, a, b, c; i < N; ++i){
    scanf("%d%d%d", &a, &b, &c), --a, --b;
    node[a].push_back(make_pair(b, c));
    node[b].push_back(make_pair(a, c));
  }
}

void dfs( void ){
  queue< int > que;
  que.push(0);
  while(!que.empty()){
    int x = que.front();
    que.pop();
    //printf("(%d, %d, %d)\n", x, p[x][0], p[x][1]);
    for(pair<int, int> i: node[x]){
      if(i.first != p[x][0]){
        que.push( i.first );
        p[ i.first ][ 0 ] = x;
        p[ i.first ][ 1 ] = i.second;
      }
    }
    node[x].clear();
  }
}

void sol(void){
  dfs();
  for(int x = 0; x < N; ++x){
    int par = p[x][0], parl = p[x][1];
    printf("%d: ", x);
    while(par >= 0 && arr[x] >= parl){
      ++ans[par];
      printf("(%d, %d):%d ", par, parl, ans[par]);
      parl += p[par][1];
      par = p[par][0];
    }
    printf("\n");
  }
  for(int i = 0; i < N; ++i){
    if(i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
}

int main(void){

  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
