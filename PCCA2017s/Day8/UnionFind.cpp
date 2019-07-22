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
inline bool check_the_same_gang(int x, int y){
  return (find(x) == find(y))? true: false;
}
int main(void){
  int i, x, y;
  char input[10];
  scanf("%d", &T);
  while(T--){
    scanf("%d %d\n", &N, &M);
    for(i = 1; i <= (N<<1); i++) par[i] = i;
    memset(level, 0, sizeof(level));
    for(i = 0; i < M; i++){
      scanf("%s %d %d\n", input, &x, &y);
      if(input[0] == 'A'){
        if(check_the_same_gang(x, y)) puts("In the same gang.");
        else if(check_the_same_gang(x, y + N)) puts("In different gangs.");
        else puts("Not sure yet.");
      }else{
        combine(x, y + N);
        combine(x + N, y);
      }
    }
  }
}
