#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, l = 0;
  char str[205];
  scanf("%s", str);
  for(i = 0, j = strlen(str); i < j; i++){
    if(str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B'){
      if(l) printf(" ");
      l = 0;
      i += 2;
    }else{
      l = 1;
      printf("%c", str[i]);
    }
  }
  printf("\n");
}
