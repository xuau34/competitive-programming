#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[10];

void ini(void){
  scanf("%d%d", &N, &M);
}

void sol(void){
  if(!M && N > 1){
    printf("-1 -1\n");
    return;
  }
  for(int i = 9; i && M; --i){
    Q += (arr[i] = M / i);
    M %= i;
  }
  if(Q > N){
    printf("-1 -1\n");
    return;
  }
  arr[0] = N - Q;
  int f = 0;
  if(N > 1 && arr[0]) printf("1"), f = 1;
  for(int i = f; i < arr[0]; ++i) printf("0");
  for(int i = 1, j; i <= 9; ++i, j = 0){
    if(arr[i] && f) printf("%d", i - 1), j = f--;
    for(; j < arr[i]; ++j) printf("%d", i);
  }
  printf(" ");
  for(int i = 9; i >= 0; --i){
    for(int j = 0; j < arr[i]; ++j) printf("%d", i);
  }
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
