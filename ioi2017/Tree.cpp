#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, edge[10005][10005];
vector<int> node[10005], Eu;

void dfs(int x, int p){
  Eu.push_back(x);
  for(int i: node[x]) if(i != p)
    dfs(i, x);
  Eu.push_back(x);
}

int main(void){
  int i, j, k;
  char str[10];
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for(i = 1; i < N; i++){
      scanf("%d %d %d", &j, &k, &Q);
      node[j].push_back(k);
      node[k].push_back(j);
      edge[j][k] = edge[k][j] = Q;
    }
    /*
    for(i = 1; i <= N; i++){
      cout<<i<<" : ";
      for(int v: node[i]) cout<<v<<" ";
      cout<<endl;
    }
    */
    dfs(1, 0);
    for(int v: Eu) cout<<v<<" ";
    cout<<endl;
    seg_build(Eu.size() * 2, -1);
    while(scanf("%s", str) && !strcmp(str, "DONE")){
    }
  }
}
