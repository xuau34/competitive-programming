#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[3][6];

void ini(void){
  scanf("%d", &N);
  scanf("%d", &M);
}

void sol(void){
  int i, j;
  arr[0][0] = 0; arr[1][0] = 1; arr[2][0] = 2;
  for(i = 1; i < 6; i++){
    if(i & 1){
      arr[0][i] = arr[1][i - 1];
      arr[1][i] = arr[0][i - 1];
      arr[2][i] = arr[2][i - 1];
    }else{
      arr[0][i] = arr[0][i - 1];
      arr[1][i] = arr[2][i - 1];
      arr[2][i] = arr[1][i - 1];
    }
  /*
  for(j = 0; j < 6; j++){
    printf("%d %d %d\n", arr[0][j], arr[1][j], arr[2][j]);
  }
  printf("--------\n\n");
  */
  }
  /*
  for(j = 0; j < 6; j++){
    printf("%d %d %d\n", arr[0][j], arr[1][j], arr[2][j]);
  }
  */
  N %= 6;
  printf("%d\n", arr[M][N]);
}

int main(void){
  int i, j;

  ini();

  sol();

}
