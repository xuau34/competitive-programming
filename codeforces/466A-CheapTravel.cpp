#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j;
  scanf("%d %d %d %d", &T, &N, &M, &Q);
  if((double)Q/(double)N < M){
    i = (T/N) * Q + (T%N) * M;
    j = ceil((double)T/(double)N) * Q;
    printf("%d\n",(i < j)? i: j);
  }else printf("%d\n", T*M);
}
