#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n, i, ans = 1;
  long long y, m;
  char s[10];
  scanf("%d", &n);
  for(i = 0, y = 20000; i < n; i++){
    cin>>m;
    scanf("%s", s);
    if((y == 20000 && s[0] != 'S') || (y == 0 && s[0] != 'N') || (s[0] == 'S' && y - m < 0) || (s[0] == 'N' && y + m > 20000)) ans = 0;
    if(s[0] == 'S') y -= m;
    else if(s[0] == 'N') y += m;
    if(y < 0) y *= (-1);
    if(y > 40000) y %= 40000;
    if(y > 20000) y = 40000 - y;
    printf("%lld %c : %lld => %d\n", m, s[0], y, ans);
  }
  if(y != 20000) ans = 0;
  if(ans) printf("YES\n");
  else printf("NO\n");
}
