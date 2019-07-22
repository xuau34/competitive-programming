#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  for(int i = 0; i < N; ++i){
    scanf("%d", &Q);
    if(Q < 0 && !M) ++T;
    else if(Q < 0) M -= 1;
    else M += Q;
  }
  printf("%d\n", T);
}

int main(void){
  int i, j;

  ini();

  sol();

}
