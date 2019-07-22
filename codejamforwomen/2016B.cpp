#include <bits/stdc++.h>
using namespace std;
int T, t, N, M, Q;

void ini(void){
  scanf("%d %d %d", &N, &M, &Q);
}

int get(int x){
  while(x <= 0) x += N;
  if(x > N) x %= N;
  while(x <= 0) x += N;
  return x;
}

void sol(void){
  int a, b, c, i;
  if(M & 1){
    a = get(M + 1 + (Q<<1));
    b = get(M - 1 + (Q<<1));
  }else{
    a = get(M - 1 - (Q<<1));
    b = get(M + 1 - (Q<<1));
  }
  if(M & 1) printf("Case #%d: %d %d\n", t, a, b);
  else  printf("Case #%d: %d %d\n", t, b, a);
}

int main(void){
  int i, j;

  scanf("%d", &T);
  for(t = 1; t <= T; t++){

  ini();

  sol();

  }
}
