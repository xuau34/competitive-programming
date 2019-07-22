#include <bits/stdc++.h>
using namespace std;
int T, N, N2, M, Q;

void ini(void){
  scanf("%d%d%d", &T, &N, &M);
}

void sol(void){
  int ans = 0;
  for(int i = 0; i < T; ++i){
    scanf("%d", &Q);
    if(Q == 1){
      if(N > 0) --N;
      else if(M > 0) --M, ++N2;
      else if(N2 > 0) --N2;
      else ++ans;
    }else if(M > 0) --M;
    else ans += 2;
    //printf("%d %d\n", N, M);
  }
  printf("%d\n", ans);

}

int main(void){
  int i, j;

  ini();

  sol();

}
