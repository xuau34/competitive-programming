#include <bits/stdc++.h>
using namespace std;
int T, N, M, K, Q, timer, par[100005][51];
int tin[100005], tou[100005], level[100005];
vector<int> node[100005];
void dfs(int x, int p){
  par[x][0] = p;
  level[x] = level[p] + 1;
  tin[x] = ++timer;
  for(int v: node[x]) if(v != p) dfs(v, x);
  tou[x] = ++timer;
}

bool anc(int x, int y){
  return tin[x] <= tin[y] && tou[y] <= tou[x];
}

int lca(int x, int y){
      //cout<<x<<" : "<<y<<" ";
  int temp = anc(y, x);
  //printf("anc(%d, %d) = %d\n", y, x, temp);
  if( anc(y, x) ) return y;
  for(int j = 20; j >= 0; j--){
    if(!anc(par[y][j], x)){
      y = par[y][j];
      //cout<<y<<" ";
    }
  }
  //cout<<endl;
  return par[y][0];
}

inline int sol(int s, int t, int f){
  int i = lca(s, f), j = lca(t, f);
  if(level[i] == level[j]) return abs(level[i] - level[f]) + abs(level[ lca(s, t) ] - level[i]) + 1;
  if(level[i] < level[j]) return abs(level[j] - level[f]) + 1; 
  return abs(level[i] - level[f]) + 1;
}

int main(void){
  int i, j, k, o, s, t, f;
  //scanf("%d", &T);
  //while(T--){
  timer = 0;
  scanf("%d%d", &N, &K);
  for(i = 2; i <= N; i++){
    scanf("%d", &j);
    node[j].push_back(i);
    node[i].push_back(j);
  }

  dfs(1, 1);

  for(int j = 1; j <= 20; j++){
    for(int i = 1; i <= N; i++) par[i][j] = par[par[i][j - 1]][j - 1];
  }

  while(K--){
    scanf("%d%d%d", &s, &t, &f);

    o = sol(s, t, f);

    o = max(o, sol(s, f, t));

    o = max(o, sol(f, t, s));
    printf("%d\n", o);
  }

}
