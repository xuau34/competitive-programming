#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d", &N, &M);
  int x;
  for(int i = 0; i < N; ++i){
    scanf("%d", &x);
    T += min(Q + x, 8);
    Q += x - min(Q + x, 8);
    if(T >= M){
      printf("%d\n", i + 1);
      return;
    }
  }
  printf("-1\n");
}

void sol(void){

}

int main(void){
  int i, j;

  ini();

  sol();

}
