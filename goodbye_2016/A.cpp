#include <bits/stdc++.h>
using namespace std;
int main(void){
  int i, n, m;
  scanf("%d %d", &n, &m);
  for(i = 0, m = 240 - m; i <= n; i++){
    if((5 * i) <= m) m -= (5 * i);
    else break;
  }
  printf("%d\n", i - 1);
}
