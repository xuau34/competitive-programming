#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, A, B, K;

void ini(void){
  scanf("%d %d", &A, &B);
}

void sol(void){
  long long sum = 0, r, k, j;
  for( int i = A; i <= B; ++i ){
    j = i / K;
    r = ( j * (i + 1) ) % 1000000007;
    k = ( ( K + j * K ) * j / 2 ) % 1000000007;
    sum = ( sum + (r + 1000000007) - k ) % 1000000007;
    //sum += ( j * (i + 1) - ( (K + j * K) * j ) / 2);
    //sum %= 1000000007;
    printf("i = %d, j = %lld, r = %lld, k = %lld, sum = %lld\n", i, j, r, k, sum);
  }
  printf("%lld\n", (sum + B - A + 1) % 1000000007);
}

int main(void){
  int i, j;
  
  scanf("%d %d", &T, &K);
  while(T--){
    ini();
    sol();
  }
}
