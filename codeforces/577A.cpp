#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d", &N, &M);
}

void sol(void){
  if( N * N < M ){
    printf("0\n");
    return;
  }
  if( (int)sqrt(M)  * (int)sqrt(M) == M && N >= sqrt(M) ) ++Q;
  //printf("%d\n", sqrt(M));
  for(int i = M, j = sqrt(M); i > j; --i) if(M % i == 0 && N >= i){
    Q += 2;
  //printf("%d\n", Q);
  }
  printf("%d\n", Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
