#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  if( N < 0 ) N = max(N / 10, (N / 100) * 10 + N % 10);
  printf("%d\n", N);
}

int main(void){
  int i, j;

  ini();

  sol();

}
