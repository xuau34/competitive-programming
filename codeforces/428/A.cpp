#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[105];

void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i){
    scanf("%d", &T);
    arr[i] = min(Q + T, 8);
    Q += T - arr[i];
    arr[i] += arr[i - 1];
    printf("%d ", arr[i]);
  }
  printf("\n");
}

inline bool check(const int &x){
  if(arr[x - 1] >= M) return true;
  for(int i = 0; i + x < N; ++i)
    if(arr[i + x] - arr[i] >= M){
      printf("check(%d) = (%d, %d) arr(%d, %d)\n", x, i, i + x, arr[i], arr[i+x]);
      return true;
    }
  return false;
}

void sol(void){
  int l = 0, r = N + 1, m;
  while(r - l > 1){
    m = (l + r) >> 1;
    if(check(m)) r = m;
    else l = m;
    printf("%d %d\n", l, r);
  }
  if(r <= N) printf("%d\n", r);
  else printf("-1\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
