#include <bits/stdc++.h>
using namespace std;
int main(void){
  char str[105], arr[10] = "hello";
  int i, j, n;
  scanf("%s", str);
  for(i = j = 0, n = strlen(str); i < n && j < 5; i++){
    if(str[i] == arr[j] || str[i] == toupper(arr[j])) j++;
  }
  if(j == 5) printf("YES\n");
  else printf("NO\n");
}
