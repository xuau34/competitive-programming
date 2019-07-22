#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, cnt[10];

void ini(void){
  scanf("%d%d", &N, &M), M = 5 - M;
  for(int i = 0; i < N; ++i) scanf("%d", &Q), ++cnt[Q];
}

void sol(void){
  for(int i = 0; i<= M; ++i) T += cnt[i];
  printf("%d\n", T / 3);
}

int main(void){
  int i, j;

  ini();

  sol();

}
