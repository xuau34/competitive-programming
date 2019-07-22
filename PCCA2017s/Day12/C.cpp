#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
pair<int, pair<int, int> > pii[105];

void ini(void){
  scanf("%d%d", &N, &M);
  int x, y, z;
  for(int i = 0; i < N; ++i){
    scanf("%d%d%d", &pii[i].second.first, &pii[i].second.second, &pii.first);
  }
}

bool check(int l){
}

void sol(void){
  if(!check(N)){
    printf("-1\n");
    return;
  }
  int l = 1, r = N, m;
  while(r - l > 1){
    m = (l + r) >> 1;
    if(check(m)) r = m;
    else l = m;
  }
  printf("%d\n", r);
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
