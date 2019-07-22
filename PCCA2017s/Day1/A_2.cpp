#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, A, B, K;
long long arr[100005], pre[100005];
void ini(void){
  scanf("%d %d", &A, &B);
}

void sol(void){
  long long sum = pre[B] - pre[A - 1];
  printf("%lld\n", (sum < 0)? sum + 1000000007: sum);
}

int main(void){
  int i, j;
  
  scanf("%d %d", &T, &K);
  arr[0] = 1;
  for( int i = 1; i <= 100000; ++i ){
    arr[i] = arr[i - 1] + ( (i - K >= 0)? arr[i - K]: 0 );
    if(arr[i] >= 1000000007) arr[i] -= 1000000007;
    pre[i] = arr[i] + pre[i - 1];
    if(pre[i] >= 1000000007) pre[i] -= 1000000007;
  }
  while(T--){
    ini();
    sol();
  }
}
