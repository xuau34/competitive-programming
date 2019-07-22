#include <bits/stdc++.h>
using namespace std;
int T, N, Q;
long long M;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  for( int i = 1; i < N; i++){
    M = i;
    for( int j = 1; j < N; j++){
      if( (M - 1) % N == 0 ){
        if( j < N - 1 ){
          //printf("i = %d, j = %d, M = %d\n", i, j, M);
          break;
        }else ++Q;
      }
      //if( j == N - 1 ) printf("i = %d, j = N - 1, M = %d => %d\n", i, M, (M - 1) % N);
      M = (M * i) % N;
    }
  }
  printf("%d\n", Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
