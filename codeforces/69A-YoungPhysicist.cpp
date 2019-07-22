#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, k, I = 0, J = 0, K = 0;
  scanf("%d", &N);
  while(N--){
    scanf("%d %d %d", &i, &j, &k);
    I += i;
    J += j;
    K += k;
  }
  if(!I && !J && !K) printf("YES\n");
  else printf("NO\n");
}
