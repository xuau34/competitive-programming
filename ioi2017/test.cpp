#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, timer, tin[100005], tou[100005], par[100005][25];
vector<int> node[100005];

void dfs(int x, int p){
  par[x][0] = p;
  tin[x] = ++timer;
  for(int v: node[x]){
    if(v != p) dfs(v, x);
  }
  tou[x] = ++timer;
}

void ini(void){
  int i, j, k;
  timer = 0;
  scanf("%d %d", &N, &Q);
  for(i = 1; i <= N; i++) node[i].clear();
  for(i = 1; i < N; i++){
    scanf("%d %d", &j, &k);
    node[j].push_back(k);
    node[k].push_back(j);
  }
  dfs(1, 1);
  for(j = 1; j <= 20; j++){
    for(i = 1; i <= N; i++){
      par[i][j] = par[ par[i][j - 1] ][j - 1];
      //cout<<par[i][j]<<" ";
    }
    //cout<<endl;
  }
}

bool anc(int x, int y){ //Is x an ancestor of y?
  return tin[x] <= tin[y] && tou[x] >= tou[y];
}

int lca(int x, int y){
  if(anc(y, x)) return y; //based on x
  for(int j = 20; j >= 0; j--){
    if(!anc(par[y][j], x)) y = par[y][j];
  }
  return par[y][0];
}

bool inpath(int x, int a, int b){ //a is anc
  return tin[x] >= tin[a] && tin[x] <= tin[b] && tou[x] >= tou[b];
  /* 
      scanf("%d %d %d %d", &u, &v, &p, &q);
      x = lca(u, v);
      y = lca(p, q);
      if(inpath(x, y, p) || inpath(x, y, q) || inpath(y, x, u) || inpath(y, x, v)) printf("tsan\n");
      else printf("hao\n");
  */
}
