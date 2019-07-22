#include <bits/stdc++.h>
using namespace std;
int main(void){
  int i, j, ans = 0;
  char str[200];
  scanf("%s", str);
  for(i = 0, j = strlen(str); i < j; i++){
    if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9') ans = 1;
  }
  if(ans) printf("YES\n");
  else printf("NO\n");
}
