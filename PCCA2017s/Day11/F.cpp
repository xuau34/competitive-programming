#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long arr[20000005];
void ini(void){
  scanf("%d%d%d", &T, &N, &M);
  for(int i = 1; i <= T << 1; ++i) arr[i] = 1e18;
}

void sol(void){
  arr[1] = N;
  for(int i = 1; i < T; ++i){
    arr[i + 1] = min( arr[i + 1], arr[i] + N );
    arr[i << 1] = min( arr[i << 1], arr[i] + M );
    for(int j = (i << 1); j && arr[j - 1] > arr[j] + N; --j){
      arr[j - 1] = arr[j] + N;
      //printf("arr[%d] = %lld\n", j - 1, arr[j - 1]);
    }
    //printf("arr[%d] = %d, arr[%d] = %d\n", i + 1, arr[i + 1], i << 1, arr[i << 1]);
  }
  printf("%lld\n", arr[T]);
}

int main(void){
  int i, j;

  ini();

  sol();

}
