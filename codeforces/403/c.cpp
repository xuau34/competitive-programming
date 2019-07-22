#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, ans[200005];
vector<int> node[200005];
void ini(void){
  scanf("%d", &N);
  for(M = 1; M < N; M++){
    scanf("%d %d", &T, &Q);
    node[T].push_back(Q);
    node[Q].push_back(T);
  }
}

void sol(int x, int p){
  int j = 1;
  for(int i = 0; i < node[x].size(); i++){
    if(node[x][i] != p){
      while(j == ans[x] || j == ans[p]) j++;
      ans[ node[x][i] ] = j++;
    }
  }
  ans[0] = max(ans[0], j);
  for(int v: node[x])
    if(v != p) sol(v, x);
}

int main(void){
  int i, j;

  ini();

  ans[1] = 1;
  sol(1, 1);

  printf("%d\n", ans[0] - 1);
  for(i = 1; i <= N; i++)
    printf("%d ", ans[i]);
  printf("\n");
}
