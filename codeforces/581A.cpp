#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d", &N, &M);
}

void sol(void){
  printf("%d %d\n", min(N, M), abs(N - M)/2);
}

int main(void){
  int i, j;

  ini();

  sol();

}
