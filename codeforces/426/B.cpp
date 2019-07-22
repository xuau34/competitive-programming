#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, clo[30];
bool ope[30], clos[1000005];
char str[1000005];
void ini(void){
  scanf("%d%d%s", &N, &M, str);
  memset(clo, -1, sizeof(clo));
  for(int i = 0; i < N; ++i){
    clo[ str[i] - 'A' ] = i;
  }
  for(int i = 0; i < 30; ++i){
    if(clo[i] >= 0)clos[ clo[i] ] = 1;
  }
}

void sol(void){
  for(int i = 0; i < N; ++i){
    if( !ope[ str[i] - 'A' ] ){
      --M;
      ope[ str[i] - 'A' ] = 1;
      if(M < 0){
        printf("YES\n");
        return;
      } 
    }
    if( clos[ i ] ){
       ++M;
       ope[ str[i] - 'A' ] = 0;
    }
  }
  printf("NO\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
