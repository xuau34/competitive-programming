#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  for(int i = 0; i < N; ++i){
    scanf("%d%d", &M, &Q);
    if(M > Q) ++T;
    else if(M < Q) --T;
  }
  if(T > 0) printf("Mishka\n");
  else if(T == 0) printf("Friendship is magic!^^\n");
  else printf("Chris\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
