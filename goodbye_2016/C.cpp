#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n, i, j, c, d, sum, l = -2147483647, r = 2147483647, f = 0;
  scanf("%d %d %d", &n, &c, &d);
  if(d == 1) l = 1900;
  else r = 1899;
  for(i = 1, sum = c; i < n; i++){
    scanf("%d %d", &c, &d);
    if(d == 1){
      j = 1900 - sum;
      if(j > r) f = 1;
      l = (j > l)? j: l;
    }else{
      j = 1899 - sum;
      if(j < l) f = 1;
      r = (j < r)? j: r;
    }
    //printf("sum=%d: l=%d, r=%d\n", sum, l, r);
    sum += c;
  }
  if(f) printf("Impossible\n");
  else if(r == 2147483647) printf("Infinity\n");
  else printf("%d\n", r + sum);
}
