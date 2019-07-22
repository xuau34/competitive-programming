#include <bits/stdc++.h>
using namespace std;
double T, N, M, Q;
const double esp = 1e-10;
void ini(void){
  scanf("%lf%lf", &N, &M);
}

void sol(void){
  if(M > N) printf("-1\n");
  else if(M == N) printf("%.10lf\n", M);
  else{
    int l = 0, r = 1000000000, m;
    while(r - l > 1){
      m = (l + r) >> 1;
      if( ( (N + M) / (m << 1) ) + esp >= M ) l = m;
      else r = m;
    }
    printf("%.10lf\n", (N + M) / (l << 1));
  }

}

int main(void){
  int i, j;

  ini();

  sol();

}
