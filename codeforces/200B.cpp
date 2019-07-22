#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
double ans;
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", &M);
    ans += M;
  }
}

void sol(void){
  printf("%.10lf\n", ans / N);
}

int main(void){
  int i, j;

  ini();

  sol();

}
