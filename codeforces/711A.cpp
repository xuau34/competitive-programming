#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[1000][10];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%s", str[i]);
}

void suc(void){
  printf("YES\n");
  for(int i = 0; i < N; ++i) printf("%s\n", str[i]);
  exit(0);
}

void sol(void){
  for(int i = 0; i < N; ++i){
    if(str[i][0] == str[i][1] && str[i][0] == 'O'){
      str[i][0] = str[i][1] = '+';
      suc();
    }else if(str[i][3] == str[i][4] && str[i][3] == 'O'){
      str[i][3] = str[i][4] = '+';
      suc();
    }
  }
  printf("NO\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
