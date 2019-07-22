#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
vector< pair<int, bool> > vii[100005];
vector<int> ans;
void ini(void){
  int a, b, c;
  scanf("%d", &N);
  for(int i = 1; i < N; ++i){
    scanf("%d%d%d", &a, &b, &c);
    --c;
    vii[a].push_back( make_pair(b,c) );
    vii[b].push_back( make_pair(a,c) );
  }
}

bool dfs(int x, int p, bool is){
  bool have = 0;
  for(int i = 0, j = vii[x].size(); i < j; ++i){
    if( vii[x][i].first != p ) have |= dfs( vii[x][i].first, x, vii[x][i].second);
  }
  if(is && !have){
    ans.push_back(x);
    return 1;
  }
  return have;
}

void sol(void){
  dfs(1, 0, 0);
  printf("%d\n", ans.size());
  for(int i: ans) printf("%d ", i);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
