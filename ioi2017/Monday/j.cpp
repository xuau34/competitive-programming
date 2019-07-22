#include <bits/stdc++.h>
int pow(int a, int n, int m) {
  long long ans = 1, tmp = a;
  while(n) {
    if(n&1) ans = ans * tmp % m;
    tmp = tmp * tmp % m;
    printf("ans=%lld tmp=%lld n=%d\n", ans, tmp, n);
    n >>= 1;
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", pow(a, b, c));
  }
  return 0;
}
