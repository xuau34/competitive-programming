#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005];

void ini(void){
  int i;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", arr + i);
  }
  sort(arr, arr+ N);
  /*
  for(i = 0; i < N; i++){
    printf("%d ", arr[i]);
  }
  */
  for(i = 0; i < N && arr[i + 1] == arr[i]; i++);
  //printf("\n%d\n", i);
  M = N - (i + 1);
  for(i = N - 1; i >= 0 && arr[i - 1] == arr[i]; i--);
  //printf("%d\n", i);
  printf("%d\n", max(M - (N - i), 0));
}

void sol(void){

}

int main(void){
  int i, j;

  ini();

  sol();

}
