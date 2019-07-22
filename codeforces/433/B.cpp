#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d", &N, &M);
  if(M > 0 && M < N) T = 1;
}

void sol(void){
  if(M > 0){
    int x = floor( (double)N / 3);
    if(M > x) Q = N - x - (M - x);
    else Q = M * 2;
  }
  printf("%d %d\n", T, Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
