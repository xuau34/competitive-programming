//lowbit of leaves decomposition
#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
int T, N, M, Q, timer, mark[MAXN], De[MAXN];
vector<int> node[MAXN];

inline int LB(int x){  //return lowerbit
  return x & (0 - x);
}

void dfs_build(int x, int p){
  int choose = 0;
  if(!node[x].size()) return mark[x] = LB(++timer);
  for(int v: node[x]){
    if(v != p) dfs_mark(v, x);
    if(mark[v] > mark[choose]) choose = v;
  }

  if(!choose) De[x] = x;
  else De[x] = choose;

  return mark[choose];
}

void input(void){
  int i, j, k;
  scanf("%d %d", &N, &M);
  for(i = 0; i < M; i++){
    scanf("%d %d", &j, &k);
    node[j].push_back(k);
    node[k].push_back(j);
  }
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    int root = 1;
    timer = 0;
    input();
    dfs_build(root, root);
  }
}
