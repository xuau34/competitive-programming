#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, n = 0;
  scanf("%d %d", &i, &j);
  while(i >= j){
    n += (int)(i / j) * j;
    i = (i / j) + (i % j);
  }
  printf("%d\n", n + i);
}
