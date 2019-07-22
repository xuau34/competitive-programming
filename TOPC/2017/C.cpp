#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long L[100005], R[100005];

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%lld%lld", L + i, R + i);
  sort(L, L + N);
  sort(R, R + N);
}

void sol(void){
  int x = 0, ans = 0;
  for(int i = 0, j = 0; i < N && j < N;){
    if(L[i] < R[j]) ++x, ++i;
    else if(L[i] == R[j]){
      ans = max(ans, x + 1);
      ++i, ++j;
    }else --x, ++j;
    ans = max(ans, x);
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){

    ini();

    sol();

  }
}
