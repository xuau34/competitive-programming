#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
vector<int> v[2005];
void ini(void){
  cin >> N;
  for(int i = 1; i <= N; ++i){
    cin >> M;
    if(M < 0) ++M;
    v[M].push_back(i);
  }
}

int dfs(int x, int h){
  int ret = h;
  for(int i = 0; i < v[x].size(); ++i) ret = max(ret, dfs( v[x][i], h + 1) );
  return ret;
}

void sol(void){
  int ans = 0;
  for(int i = 0; i < v[0].size(); ++i) ans = max( ans, dfs( v[0][i], 1) );
  cout << ans << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
