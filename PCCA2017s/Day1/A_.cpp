#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, A, B, K;

void ini(void){
  scanf("%d %d", &A, &B);
}

void sol(void){
  long long sum = 0, now = 1, add = 0;
  for( int i = 1; i <= B; ++i ){
    if( i % K == 0 ) ++add;
    now += add;
    if( i >= A ) sum = (sum + now) % 1000000007;
    printf("i = %d, now = %lld, sum = %lld\n", i, now, sum);
  }
  printf("%lld\n", sum);
}

int main(void){
  int i, j;
  
  scanf("%d %d", &T, &K);
  while(T--){
    ini();
    sol();
  }
}
