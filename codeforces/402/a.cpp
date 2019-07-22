#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[2][10];

void ini(void){
  int i, j;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &j);
    arr[0][j]++;
  }
  for(i = 0; i < N; i++){
    scanf("%d", &j);
    arr[1][j]++;
  }
}

void sol(void){
  int i, j, a, b;
  for(i = 1; i <= 5; i++){
    if((arr[0][i] + arr[1][i]) & 1){
      printf("-1\n");
      return;
    }
  }
  for(i = 1, a = b = 0; i <= 5; i++){
    j = ((arr[0][i] + arr[1][i])>>1) - arr[0][i];
    if(j > 0) a += j;
    else b += j;
  }
  if(a != (0 - b)){
    printf("-1\n");
    return;
  }else{
    printf("%d\n", a);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
