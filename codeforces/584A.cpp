#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d", &N, &M);
}

void sol(void){
  if(M == 10){
    if(N < 2) printf("-1"); //M = 10 時必N >= 2
    else{
      for(int i = 0; i < N - 1; ++i) printf("1");
      printf("0\n");
    }
  }else{
    for(int i = 0 ; i < N; ++i) printf("%d", M);
    printf("\n");
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
