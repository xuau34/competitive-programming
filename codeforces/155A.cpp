#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, ans;

void ini(void){
  scanf("%d%d", &N, &M);
  Q = M;
  for(int i = 1; i < N; ++i){
    scanf("%d", &T);
    if(T < M || T > Q) ++ans;
    M = min(M, T);
    Q = max(Q, T);
  }
}

void sol(void){
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
