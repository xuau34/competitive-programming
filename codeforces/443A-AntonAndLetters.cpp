#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool arr[500];
int main(void){
  int ans = 0;
  char str[1500], c;
  while(~scanf("%s", str)){
    if(str[strlen(str) - 1] == '}') c = str[strlen(str) - 2];
    else c = str[strlen(str) - 2];
    if(!arr[(int)c] && isalpha(c)){
      arr[(int)c] = 1;
      ans++;
    }
  }
  printf("%d\n", ans);
}
