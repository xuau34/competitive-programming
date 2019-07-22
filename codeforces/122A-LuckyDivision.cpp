#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n, i, ans = 0, j, f;
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    if(!(n % i)){
      j = i;
      while(j > 0 && (j % 10 == 4 || j % 10 == 7)) j /= 10;
      if(j == 0) ans = 1;
    }
  }
  if(ans) printf("YES\n");
  else printf("NO\n");
}
