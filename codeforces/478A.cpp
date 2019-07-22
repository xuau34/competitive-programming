#include <bits/stdc++.h>
using namespace std;
int T, M, Q;
double N;

void ini(void){
  for(int i = 0; i < 5; ++i){
    scanf("%d", &T);
    N += T;
  }
}

void sol(void){
  N /= 5;
  if((int)N == 0 || N > ((int)N)) printf("-1\n"); //因為必定要能夠給出一個coin
  else printf("%d\n", (int)N);
}

int main(void){
  int i, j;

  ini();

  sol();

}
