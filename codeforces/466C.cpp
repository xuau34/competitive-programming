#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[(int)5e5 + 10];
long long total;
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i), total += arr[i];
}

int sol(void){
  if(total % 3 || N < 3) return 0;
  if( (M = total / 3) == 0 ){
    int ans = 0, sum = 0;
    for(int i = 0; i < N; ++i){
      sum += arr[i];
      if(sum == 0) ++ans;
    }
    printf("ans = %d\n", ans);
    if(ans < 3) return 0;
    if(ans == 3) return 1;
    return 3 * (ans - 3);
  }else{
    int l = 0, r = N - 1, sum = 0, l0 = 0, r0 = 0;
    for(; l < N && sum != M; ++l) sum += arr[l];
    if(l-- == N) return 0;
    for(sum = 0; r > l && sum != M; --r) sum += arr[r];
    if(r++ == l) return 0;
    printf("l = %d, r = %d\n", l, r);
    for(int i = l + (sum = 0) + 1;; ++i){
      sum += arr[i];
      if(sum == 0) ++l0;
      if(sum == M){
        l = i, sum = 0;
        break;
      }
      if(i == r) return 0;
    }
    printf("l0 = %d ", l0);
    for(int i = l + 1; i < r; ++i){
      sum += arr[i];
      if(sum == 0) ++r0;
    }
    printf("r0 = %d\n", r0);
    return (l0 + 1) * (r0 + 1);
  }
}

int main(void){
  int i, j;

  ini();

  printf( "%d\n", sol() );

}
