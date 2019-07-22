#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int T, N, M, Q, dp[10005][30];
vector<int> arr[10005], leaves;
long long ans;
char str[10005];

void predfs(int x, int p){
  if(arr[x].size() == 1 && arr[x][0] == p){
    leaves.push_back(x);
    return;
  }
  for(int y: arr[x]){
    if(y == p) continue;
    predfs(y, x);
  }
}

void ini(void){
  leaves.clear();
  memset(dp, 0, sizeof(dp));
  scanf("%d", &N);
  for(int i = 1, a, b; i < N; ++i){
    scanf("%d%d", &a, &b);
    arr[--a].push_back(--b);
    arr[b].push_back(a);
  }
  ans = 0;
  scanf("%s", str);
  predfs(0, 0);
  sort(leaves.begin(), leaves.end());
  for(int i = 0, j = leaves.size(); i < j; ++i)
    dp[leaves[i]][26] = str[i] - 'A';
}

void dfs(int x, int p){
  if(arr[x].size() == 1 && arr[x][0] == p){
    arr[x].clear();
    return;
  }
  int mx = 0, tmp;
  for(int y: arr[x]){
    if(y == p) continue;
    dfs(y, x);
    ++dp[x][tmp = dp[y][26]];
    if(dp[x][mx] < dp[x][tmp]) mx = tmp;
  }
  dp[x][26] = mx;
  arr[x].clear();
  for(int i = 0; i < 26; ++i){
    if(i == mx) continue;
    ans += dp[x][i];
  }
}

void sol(void){
  dfs(0, 0);
  printf("%lld\n", ans);
}

int main(void){
  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
