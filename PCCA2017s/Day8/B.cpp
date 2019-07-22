#include <iostream>
#include <cstring>
using namespace std;
int par[200005], level[200005], T, N, M;
int find(int x){
  return (par[x] == x)? x: par[x] = find(par[x]);
}
void combine(int x, int y){
  x = find(x); y = find(y);
  if(x!=y){
    level[x] > level[y] ? par[y] = x: par[x] = y;
    if(level[x] == level[y]) level[y]++;
  }
}

void ini(void){
  scanf("%d", &N);
  for(int i = 1; i <= (N<<1); i++) par[i] = i;
}
void sol(void){
  for(int i = 1; i <= N; ++i){
    scanf("%d", &M);
    combine(i, M);
  }
  for(int i = 1; i <= N; ++i){
    if(par[i] == i) ++T;
  }
  printf("%d\n", T);
}
int main(void){
  ini();
  sol();
}
