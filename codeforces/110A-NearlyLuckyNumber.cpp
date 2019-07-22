#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, ans = 0;
  string str;
  cin>>str;
  for(i = N = 0, j = str.length(); i < j; i++){
    if(str[i] == '4' || str[i] == '7') N++;
  }
  
  j = N;
  while(j > 0 && (j % 10 == 4 || j % 10 == 7)) j /= 10;
  if(j == 0) ans = 1;

  if(ans && N) printf("YES\n");
  else printf("NO\n");
}
