#include <bits/stdc++.h>
using namespace std;
int T, C, V, L;
long long c, v, p;
void ini(void){
  scanf("%d %d %d", &C, &V, &L);
}

void sol(void){
  long long tc, tv;
  c = 0;
  v = V;
  while(--L){
    tc = (v * C) % p;
    tv = ((c + v) * V) % p;
    c = tc;
    v = tv;
    //printf("c = %lld v = %lld\n", c, v);
  }
}

int main(void){
  int i, j;
  p = 1000000007;
  scanf("%d", &T);
  for(i = 1; i <= T; i++){

    ini();

    sol();
    printf("Case #%d: %lld\n", i, (c + v) % p);
  }
}
