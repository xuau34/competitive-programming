#include <bits/stdc++.h>
using namespace std;
int T, N, M, K, Q, timer, par[100005][51];
int tin[100005], tou[100005];
vector<int> node[100005];
void dfs(int x, int p){
  par[x][0] = p;
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

/*
bool check(int u, int v, int U, int V){
  int x = lca(u, v), y = lca(U, V);
  if(x == y) return true;

  int X = ((tin[U] < tin[y])? tin[U]: tin[y]), Y = ((tin[U] < tin[y])? tin[y]: tin[U]);
  //printf("lca(%d, %d) = %d ; %d <= %d <= %d \n", U, y, x, X, tin[x], Y);
  if(X <= tin[x] && tin[x] <= Y && tou[x] >= Y) return true;

  X = ((tin[y] < tin[V])? tin[y]: tin[V]), Y = ((tin[y] < tin[V])? tin[V]: tin[y]);
  //printf("lca(%d, %d) = %d ; %d <= %d <= %d \n", y, V, x, X, tin[x], Y);
  if(X <= tin[x] && tin[x] <= Y && tou[x] >= Y) return true;

  X = ((tin[u] < tin[x])? tin[u]: tin[x]), Y = ((tin[u] < tin[x])? tin[x]: tin[u]);
  //printf("lca(%d, %d) = %d ; %d <= %d <= %d \n", u, x, y, X, tin[y], Y);
  if(X <= tin[y] && tin[y] <= Y && tou[y] >= Y) return true;

  X = ((tin[x] < tin[v])? tin[x]: tin[v]), Y = ((tin[x] < tin[v])? tin[v]: tin[x]);
  //printf("lca(%d, %d) = %d ; %d <= %d <= %d \n", x, v, y, X, tin[y], Y);
  if(X <= tin[y] && tin[y] <= Y && tou[y] >= Y) return true;
  return false;
}
*/

int main(void){
  int i, j, k, o;
  scanf("%d", &T);
  while(T--){
    timer = 0;
    scanf("%d %d", &N, &K);
    for(i = 1; i < N; i++){
      scanf("%d %d", &j, &k);
      node[j].push_back(k);
      node[k].push_back(j);
    }

    dfs(1, 1);

    for(int j = 1; j <= 20; j++){
      for(int i = 1; i <= N; i++) par[i][j] = par[par[i][j - 1]][j - 1];
    }

    /*
    for(int i = 1; i <= N; i++){
      cout<<i<<" : ";
      for(int j = 0; j <= 100; j++) cout<<par[i][j]<<" ";
      cout<<endl;
    }
    */
    //cout<<lca(2, 3)<<endl;
    /*
    while(K--){
      scanf("%d %d %d %d", &i, &j, &k, &o);
      if(check(i, j, k, o)) printf("tsan\n");
      else printf("hao\n");
    }
    */
    //for(int i = 1; i <= N; i++) cout<<tin[i]<<","<<tou[i]<<" ";
    //cout<<endl;
    for(i = 1; i <= N; i++) node[i].clear();
  }
}
