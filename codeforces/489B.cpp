#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, cnt[2][105];

void ini(void){
  scanf("%d", &N);
  for(int i = 0, j; i < N; ++i) scanf("%d", &j), ++cnt[0][j], Q = max(Q, j);
  scanf("%d", &M);
  for(int i = 0, j; i < M; ++i) scanf("%d", &j), ++cnt[1][j], Q = max(Q, j);
}

void sol(void){
  int ans = 0;
  for(int i = 1; i <= Q; ++i){
    if(cnt[0][i - 1] && cnt[1][i]){
      int x = min(cnt[0][i - 1], cnt[1][i]);
      ans += x, cnt[1][i] -= x;
    }
    if(cnt[0][i] && cnt[1][i - 1]){
      int x = min(cnt[0][i], cnt[1][i - 1]);
      ans += x, cnt[0][i] -= x;
    }
    if(cnt[0][i] && cnt[1][i]){
      int x = min(cnt[0][i], cnt[1][i]);
      ans += x, cnt[0][i] -= x, cnt[1][i] -= x;
    }
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
