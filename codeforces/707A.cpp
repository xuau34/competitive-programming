#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d", &N, &M);
}

void sol(void){
  char str[10];
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      scanf("%s", str);
      if(str[0] == 'C' || str[0] == 'M' || str[0] == 'Y'){
        printf("#Color\n");
        exit(0);
      }
    }
  }
  printf("#Black&White\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
