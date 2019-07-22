#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  long long pre = 0, sum = 0;
  for(long long i = 1; i <= 10000; ++i){
    pre += i;
    sum += pre;
    if(sum > N){
      printf("%lld\n", i - 1);
      return;
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
