#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[15][15];

void ini(void){
  scanf("%d", &N);
  T = 1;
  for(int i = 0; i < N; ++i) arr[i][0] = arr[0][i] = 1;
}

void sol(void){
  for(int i = 1; i < N; ++i){
    for(int j = 1; j < N; ++j){
      arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
      T = max(T, arr[i][j]);
    }
  }
  printf("%d\n", T);
}

int main(void){
  int i, j;

  ini();

  sol();

}
