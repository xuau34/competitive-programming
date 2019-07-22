#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, k, n, w;
  scanf("%d %d %d", &k, &n, &w);
  for(i = 1, j = 0; i <= w; i++){
    j += (k * i);
  }
  if(j > n) printf("%d\n", j - n);
  else printf("0\n");
}
