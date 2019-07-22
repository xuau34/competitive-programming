#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  if(N & 1) printf("7");
  else printf("1");
  M = (N >> 1) - 1;
  while(M--) printf("1");
  printf("\n");
}

int main(void){

  ini();

  sol();

}
