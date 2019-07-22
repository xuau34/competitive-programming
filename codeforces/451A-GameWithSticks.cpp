#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j;
  scanf("%d %d", &i, &j);
  i = min(i, j);
  if(i & 1) printf("Akshat\n");
  else printf("Malvika\n");
}
