#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, v[200005];
vector<int> child[200005];
void ini(void){
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i){
    scanf("%d %d", &M, v + i);
    if(M < 0) Q = i;
    else child[M].push_back(i);
  }
}

long long dfs( int x ){
  if( child[x].size() <= 1 ) return v[x];

  long long sum = 0, mn = LLONG_MAX, temp;
  for(int i: child[x]){
    temp = dfs(i);
    sum += temp;
    mn = min(mn, temp);
  }
  //printf("dfs(%d): sum = %lld, mn = %lld\n", x, sum, mn);
  /*
  for(int i = 1; i <= N; ++i) printf("%d ", v[i]);
  printf("\n");
  */

  if(child[x].size() & 1) return v[x] + sum - mn;
  else return v[x] + sum;
}

void sol(void){
  printf("%lld\n", dfs( Q ) );
  //for(int i = 1; i <= N; ++i) printf("%d ", v[i]);
  //printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
