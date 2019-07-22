#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
double r, ax, ay, bx, by, cx, cy, x, y;
const double esp = 1e-9;

void ini(void){
  scanf("%lf%lf", &ax, &ay), bx = cx = ax, by = cy = ay;
  r = 0;
}

inline bool check(void){
  double XD = (x - cx) * (x - cx) + (y - cy) * (y - cy) - r * r;
  return XD <= esp;
}

inline bool dis(void){
  double d0 = (x - ax) * (x - ax) + (y - ay) * (y - ay), d1 = (x - bx) * (x - bx) + (y - by) * (y - by);
  return d0 >= d1;
}

void sol(void){
  for(int i = 1; i < N; ++i){
    scanf("%lf%lf", &x, &y);
    if( !check() ){
      if( dis() ) bx = x, by = y;
      else ax = x, ay = y;
      cx = (ax + bx) / 2, cy = (ay + by) / 2, r = sqrt( (ax - bx) * (ax - bx) + (ay - by) * (ay - by) ) / 2;
    }
  }
  printf("%.2lf %.2lf %.2lf\n", cx, cy, r);
}

int main(void){
  int i, j;

  while( scanf("%d", &N) && N ){
    ini();
    sol();
  }
}
