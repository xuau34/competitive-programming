#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  scanf("%d", &N);
  int i = N / 2, j = N - i, ii, jj;
  while(i > 1 && j < N){
    ii = 2; jj = 2;
    while(i % ii) ii++;
    while(j % jj) jj++;
    if(ii != i && jj != j){
      printf("%d %d\n", i, j);
      return 0;
    }
    i--; j++;
  }
}
