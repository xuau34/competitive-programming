#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[5];
char str[105];
void ini(void){
  scanf("%s", str);
}

void sol(void){
  int len = strlen(str);
  for(int i = 0; i < len; i += 2){
    ++arr[ str[i] - '0' ];
    M = max(M, str[i] - '0');
  }
  for(int i = 1; i <= 3; ++i){
    for(int j = 0; j < arr[i]; ++j){
      printf("%d", i);
      if(i == M && j == arr[i] - 1) printf("\n");
      else printf("+");
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
