#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j;
  char str1[105], str2[105];
  scanf("%s %s", str1, str2);
  for(i = 0, j = strlen(str1); i < j; i++){
    if((int)(str1[i] - '0')^(int)(str2[i] - '0')) str1[i] = '1';
    else str1[i] = '0';
  }
  printf("%s\n",str1);
}
