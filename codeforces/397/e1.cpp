#include <bits/stdc++.h>
using namespace std;
int T, N, M, L, tag[200005];
vector<int> node[200005];
void ini(void){
  int i, j, k;
  scanf("%d", &N);
  for(i = 1; i < N; i++){
    scanf("%d %d", &j, &k);
    node[j].push_back(k);
    node[k].push_back(j);
  }
}

int dfs(int x, int p, int first){
  if(first){
    int j, k = x;
    tag[x] = tag[p] + 1;
    for(int i = 0; i < node[x].size(); i++){
      if(node[x][i] != p){
        j = dfs(node[x][i], x, first);
        if(tag[j] > tag[k]) k = j;
      }
    }
    return k;
  }else{
    int j, k = 0;
    if(x != p && tag[x] - 1 <= tag[p] + 1 && tag[x] + 1 >= tag[p] + 1) return x;
    tag[x] = tag[p] + 1;
    for(int i = 0; i < node[x].size(); i++){
      if(node[x][i] != p){
        j = dfs(node[x][i], x, first);
        if(!k && j) k = j;
      }
    }
    return k;
  }
}

int combine(int x, int p){
  int i, j, k = 0;
  map<int, int> ma;
  map<int, int>::iterator ite;
  for(i = 0; i < node[x].size(); i++){
    if(node[x][i] != p){
      j = combine(node[x][i], x);
      if(j < 0) return -1;
      ma[j]++;
    }
  }
  //printf("node[%d]: ", x);
  for(ite = ma.begin(), j = 0; ite != ma.end(); ++ite){
    //printf("(%d, %d) ", ite->first, ite->second);
    j++;
    k += ite->first;
  }
  if(x != p && j > 1) return -1;
  if(x == p && j > 2) return -1;
  //printf("\nnode[%d] return %d\n", x, k+1);
  return k + 1;
}

void sol(void){
  int c = dfs(1, 1, 1);
  tag[c] = -1;
  c = dfs(c, c, 1);
  tag[c] = -1;
  c = dfs(c, c, 0);

  int ans = combine(c, c);
  if(ans < 0){
    printf("-1\n");
  }else{
    --ans;
    while(!(ans & 1)) ans >>= 1;
    printf("%d\n", ans);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
