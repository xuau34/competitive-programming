#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[105];

void ini(void){
  scanf("%d%d", &N, &M);
  Q = N / M;
  for(int i = 0 ; i < N; ++i){
    scanf("%d", &T);
    ++arr[T];
  }
}

void sol(void){
  int ans = 0, j;
  for(int i = T = 1; i <= M; ++i){
    if( arr[i] <= Q ) continue;
    ans += arr[i] - Q;
    /*
    for( ; T <= M; ++T ){
      if( arr[T] >= Q ) continue;
      j = min( Q - arr[T], arr[i] - Q );
      ans += j;
      arr[T] += j;
      arr[i] -= j;
      //printf("arr[%d] = %d, arr[%d] = %d\n", i, arr[i], T, arr[T]);
    }
    */
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
