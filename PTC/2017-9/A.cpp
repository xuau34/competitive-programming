#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[505];
void ini(void){
  scanf("%s", str);
}

bool sol(void){
  int num = 1;
  for(int i = 0, j = strlen(str), n = 0; i < j; ++i){
    if(str[i] == '(') ++n;
    else if(str[i] == ')'){
      if(n > 0 && num != 1) --n;
      else return 0;
    }else if(str[i] >= '0' && str[i] <= '9'){
      if(num){
        while(str[i + 1] >= '0' && str[i + 1] <= '9') ++i;
        num = 0;
      }else return 0;
    }else{
      if(num) return 0;
      else num = 1;
    }
  }
  if(num) return 0;
  return 1;
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){

    ini();

    if(sol()) printf("legal expression\n");
    else printf("illegal expression\n");

  }
}
