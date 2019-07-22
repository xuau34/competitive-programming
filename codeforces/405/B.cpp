#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
vector<int> arr[150005], s;
bool vis[150005];
void ini(void){
  scanf("%d %d", &N, &M);
  while(M--){
    scanf("%d %d", &T, &Q);
    arr[T].push_back(Q);
    arr[Q].push_back(T);
  }
}

int dfs(int x){
  s.push_back(x);
  vis[x] = 1;
  int count = 1;
  for(int v: arr[x]){
    if(!vis[v]) count += dfs(v);
  }
  return count;
}

void sol(void){
  int X;
  for(int i = 1; i <= N; i++){
    if(vis[i]) continue;
    X = dfs(i);
    for(int v: s){
      if(arr[v].size() != X - 1){
        printf("NO\n");
        return;
      }
    }
    s.clear();
  }
  printf("YES\n");
  return;
}

int main(void){
  int i, j;

  ini();

  sol();

}
