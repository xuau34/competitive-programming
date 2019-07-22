#include <bits/stdc++.h>
using namespace std;
bool arr[500];
int main(void){
  char str[150];
  int i, n;
  scanf("%s", str);
  for(i = 0, n = strlen(str); i < n; i++){
    arr[str[i] - 'a'] = 1;
  }
  for(i = n = 0; i < 500; i++){
    if(arr[i]) n++;
  }
  if(n & 1) printf("IGNORE HIM!\n");
  else printf("CHAT WITH HER!\n");
}
