#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  Q = N;
  for(int i = 1; i < N; ++i) Q += i * (N - i); 
  printf("%d\n", Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
