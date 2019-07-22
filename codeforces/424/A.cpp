#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[105];

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
  int i = 0;
  for(; i < N; ++i){
    if(arr[i] >= arr[i + 1]) break;
  }
  //printf("i = %d\n", i);
  if(i == N){
    printf("NO\n");
    exit(0);
  }
  for(; i < N; ++i){
    if(arr[i + 1] < arr[i]) break;
    else if(arr[i + 1] > arr[i]){
      printf("NO\n");
      exit(0);
    }
  }
  //printf("i = %d\n", i);
  if(i == N && arr[i - 1] == arr[i - 2]){
    printf("NO\n");
    exit(0);
  }
  for(; i < N; ++i){
    if(arr[i + 1] < arr[i]) Q = M;
    else{
      printf("NO\n");
      exit(0);
    }
  }
  printf("YES\n");
}

void sol(void){

}

int main(void){
  int i, j;

  ini();

  sol();

}
