#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  for(int i = floor((double)N / 2); i > 0; i--){
    if(__gcd(i, N - i) == 1){
      printf("%d %d\n", i, N - i);
      return;
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
