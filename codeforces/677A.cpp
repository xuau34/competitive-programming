#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i){
    scanf("%d", &Q);
    if(Q > M) T += 2;
    else ++T;
  }
}

void sol(void){
  printf("%d\n", T);
}

int main(void){
  int i, j;

  ini();

  sol();

}
