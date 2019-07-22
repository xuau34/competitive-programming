#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool arr[30];
int main(void){
  int i, j;
  char str[105];
  scanf("%d\n", &N);
  scanf("%s", str);
  for(i = j = 0; i < N; i++){
    str[i] = tolower(str[i]);
    if(!arr[str[i] - 'a']){
      arr[str[i] - 'a'] = 1;
      j++;
    }
  }
  if(j != 26) printf("NO\n");
  else printf("YES\n");
}
