#include <bits/stdc++.h>
using namespace std;
const double esp = 1e-9;
int main(void){
  double A, B, N, M;
  for(int i = 1; i <= 1000000000; ++i){
    N = i;
    for(int j = i; j; --j){
      M  = j;
      int l = 0, r = 1000000000, m;
      while(r - l > 1){
        m = (l + r) >> 1;
        if( ( (N + M) / (m << 1) ) + esp >= M ) l = m;
        else r = m;
      }
      A = (N + M) / (l << 1);

      l = 0, r = 1000000000;
      while(r - l > 1){
        m = (l + r) >> 1;
        if( ( (N - M) / (m << 1) ) + esp >= M ) l = m;
        else r = m;
      }
      B = (N - M) / (l << 1);

      if(B < A) printf("(%d, %d) ", i, j);
    }
  }
}
