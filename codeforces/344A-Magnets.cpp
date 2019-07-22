#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, p, n = 1;
  scanf("%d", &N);
  scanf("%d", &i);
  p = i; N--;
  while(N--){
    scanf("%d", &i);
    if(p + i == 11){
      n++;
      p = i;
    } 
  }
  printf("%d\n", n);
}
