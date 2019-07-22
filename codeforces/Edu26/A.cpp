#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[205];
void ini(void){
  scanf("%d", &N);
}

void sol(void){
  while( ~scanf("%s", str) ){
    for(int i = M = 0, j = strlen(str); i < j; ++i){
      if(isupper(str[i])) ++M;
    }
    Q = max(Q, M);
  }
  printf("%d\n", Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
