#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long arr[5005];

void ini(void){
  arr[1] = 1;
  for(int i = 2; i <= 5000; ++i) arr[i] = arr[i - 1] + arr[i - 2];
}

void sol(void){
  while(scanf("%d", &N) == 1){
    printf("The Fibonacchi number for %d is %lld\n", N, arr[N]);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
