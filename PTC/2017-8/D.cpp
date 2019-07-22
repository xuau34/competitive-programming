#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d%d", &N, &M, &Q);
  --M, --Q;
}

void sol(void){
  int up = N - M - 1, right = N - Q - 1, down = M, left = Q;
  long long ans = 0, ret = 0;
  for(int i = 1; i <= N; ++i) ret += (N - i) * (N - i) * i;
  printf("up = %d, right = %d, down = %d, left = %d\n", up, right, down, left);
  ans = min(up, right) + min(up, left) + min(down, right) + min(down, left);
  printf("%lld\n", ans);
  for(int i = min(up - 1, left); i > 0; --i){
    for(int j = 1; j <= right && j + i <= up; ++j) ++ans;
  }
  printf("%lld\n", ans);
  for(int i = min(down - 1, left); i > 0; --i){
    for(int j = 1; j <= right && j + i <= down; ++j) ++ans;
  }
  printf("%lld\n", ans);
  for(int i = min(left - 1, up); i > 0; --i){
    for(int j = 1; j <= down && j + i <= left; ++j) ++ans;
  }
  printf("%lld\n", ans);
  for(int i = min(right - 1, up); i > 0; --i){
    for(int j = 1; j <= down && j + i <= right; ++j) ++ans;
  }
  printf("%lld\n", ret - ans);
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){

    ini();

    sol();

  }
}
