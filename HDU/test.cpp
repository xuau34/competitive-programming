#include <bits/stdc++.h>
using namespace std;
struct PT{
  double x, y;
} A, B, C;

struct PT center( const struct PT &a, const struct PT &b, const struct PT &c){
  double d = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) * 2.;
  double A = a.x * a.x + a.y * a.y, B = b.x * b.x + b.y * b.y, C = c.x * c.x + c.y * c.y;
  struct PT ret;
  ret.x = (A * (b.y - c.y) + B * (c.y - a.y) + C * (a.y - b.y)) / d;
  ret.y = (A * (c.x - b.x) + B * (a.x - c.x) + C * (b.x - a.x)) / d;
  return ret;
}

int main(void){
  while( scanf("%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y) ){
    C = center(A, B, C);
    printf("(%lf, %lf)\n", C.x, C.y);
  }
}
