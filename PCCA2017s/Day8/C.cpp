#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool m[305][305];
vector<int> s[305], p[305];
int par[3005], level[3005], arr[3005];
int find(int x){
  return (par[x] == x)? x: par[x] = find(par[x]);
}
void combine(int x, int y){
  x = find(x); y = find(y);
  if(x!=y){
    level[x] > level[y] ? par[y] = x: par[x] = y;
    if(level[x] == level[y]) level[y]++;
  }
}

void ini(void){
  char str[305];
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
  for(int i = 0; i < N; ++i){
    scanf("%s", str);
    for(int j = 0; j < N; ++j) m[i][j] = str[j] - '0';
  }
  for(int i = 1; i <= (N<<1); i++) par[i] = i;
}

void sol(void){
  for(int i = 0; i < N; ++i) for(int j = i + 1; j < N; ++j) if(m[i][j]) combine(i, j);
  for(int i = 0; i < N; ++i) if(par[i] != i) s[ find(i) ].push_back( arr[i] ), p[ find(i) ].push_back( i );
  for(int i = 0; i < N; ++i){
    if(s[i].empty()) continue;
    s[i].push_back( arr[i] );
    p[i].push_back( i );
    sort(s[i].begin(), s[i].end());
    sort(p[i].begin(), p[i].end());
    //printf("%d: ", i);
    for(int j = 0, k = s[i].size(); j < k; ++j){
      //printf("(%d, %d) ", p[i][j], s[i][j]);
      arr[ p[i][j] ] = s[i][j];
    }
    //printf("\n");
  }
  for(int i = 0; i < N; ++i) printf("%d ", arr[i]);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
