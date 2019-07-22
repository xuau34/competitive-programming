#include <iostream>
using namespace std;
int T, N, M, Q, arr[100005], cnt[100005];

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
}

void sol(void){
  int Mi, Ma, ans = 0;
  Mi = Ma = arr[0];
  for(int l = 0, r = 0; l < N; ++l){
    ++cnt[ arr[l] ];
    Mi = min(arr[l], Mi), Ma = max()
    for(; r < N && max( arr[r + 1], Ma ) - min( arr[r + 1], Mi ) <= 1; ++r) ++cnt[ arr[r + 1] ];
    printf("(%d, %d)\n", l, r);
    ans = max(r - l, ans);
    --cnt[ arr[l] ];
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
