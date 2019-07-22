#include <bits/stdc++.h>
using namespace std;
int T, N, M, L, tag[200005];
vector<pair<int, int> > node[200005];
void ini(void){
  int i, j, k;
  scanf("%d", &N);
  for(i = 1; i < N; i++){
    scanf("%d %d", &j, &k);
    node[j].push_back(make_pair(0, k) );
    node[k].push_back(make_pair(0, j) );
  }
}

int dfs(int x, int p, int first){
  if(first){
    int j, k = x;
    tag[x] = tag[p] + 1;
    for(int i = 0; i < node[x].size(); i++){
      if(node[x][i].second != p){
        j = dfs(node[x][i].second, x, first);
        if(tag[j] > tag[k]) k = j;
      }
    }
    return k;
  }else{
    int j, k = 0;
    if(x != p && tag[x] - 1 <= tag[p] + 1 && tag[x] + 1 >= tag[p] + 1) return x;
    tag[x] = tag[p] + 1;
    for(int i = 0; i < node[x].size(); i++){
      if(node[x][i].second != p){
        j = dfs(node[x][i].second, x, first);
        if(!k && j) k = j;
      }
    }
    return k;
  }
}

int combine(int x, int p){
  int i, j, k = 0;
  for(i = 0; i < node[x].size(); i++){
    if(node[x][i].second != p){
      j = combine(node[x][i].second, x);
      if(j < 0) return -1;
      node[x][i].first = j;
      if(j > k) k = j;
    }
  }
  sort(node[x].begin(), node[x].end());
  if(x != p) i = 2;
  else i = 1;
  for(; i < node[x].size(); i++){
    if(node[x][i].first == node[x][i - 1].first){
      node[x][i - 1].first = -1;
    }else if(x != p){
      return -1;
    }
  }
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
    int j = 0;
    ans = 0;
    for(int i = 0; i < node[c].size(); i++){
      if(node[c][i].first > 0){
        ++j;
        ans += node[c][i].first;
      }
    }
    if(j > 2) printf("-1\n");
    else{
      while(!(ans & 1)) ans >>= 1;
      printf("%d\n", ans);
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
