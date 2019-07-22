#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  for(int i = 1; i <= N; ++i){
    if(i & 1) printf("I hate ");
    else printf("I love ");
    if(i < N) printf("that ");
    else printf("it\n");
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
