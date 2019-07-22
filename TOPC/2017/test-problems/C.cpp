#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
double A;
const double eps = 1e-5, pi = acos(-1);
int cmp( double x ) {
  if( fabs(x) < eps ) return 0;
  if( x > 0 ) return 1;
  return -1;
}

void sol(void){
  double dx = abs(T - M), dy = abs(N - Q), r = sqrt(dx * dx + dy * dy) / 2, a = r * r * pi;
  if( cmp(a - A) == 0 ){
    printf("Circle %.9lf\n", 2 * pi * r);
    return;
  }
  a = dx * dy;
  if( cmp(a - A) == 0 && cmp(dx - dy) == 0 ){
    printf("Square %.9lf\n", 2 * (dx + dy));
    return;
  }
  printf("MZ is a liar!\n");
}

int main(void){
  int i, j;
  while(~scanf("%lf%d%d%d%d", &A, &T, &N, &M, &Q)){
    sol();
  }
}
