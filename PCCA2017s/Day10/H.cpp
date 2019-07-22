#include <bits/stdc++.h>
using namespace std;
double T, N, M, Q;
const double pi = acos(-1);
void ini(void){
  scanf("%lf%lf%lf%lf", &T, &N, &M, &Q);
  //printf("pi = %lf\n", pi);
}

void sol(void){
  double V = M - (T / 2) * (T / 2) * pi * Q;
  if(V < 0) printf("NO\n");
  else{
    printf("YES\n%.15lf\n", ( (T / 2)*(T / 2) * pi * N) / V);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
