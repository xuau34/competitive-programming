#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, k;
  scanf("%d %d %d", &i, &j, &k);
  printf("%d\n", max( max((i + j + k), (i + j) * k), max( max((i + j * k), (i * j + k)), max(i * (j + k), i * j * k))));
}
