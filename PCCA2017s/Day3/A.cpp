#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[100005];
void ini(void){
  scanf("%s", str);
}

void sol(void){
  int len = strlen(str);
  for(int i = 1; i < len; ++i){
    if(str[i - 1] == 'A' && str[i] == 'B'){
      for(int j = 1; j < len; ++j){
        if(j == i - 1 || j == i || j - 1 == i ) continue;
        if(str[j - 1] == 'B' && str[j] == 'A'){
          printf("YES\n");
          return;
        }
      }
    }else if(str[i - 1] == 'B' && str[i] == 'A'){
      for(int j = 1; j < len; ++j){
        if(j == i - 1 || j == i || j - 1 == i ) continue;
        if(str[j - 1] == 'A' && str[j] == 'B'){
          printf("YES\n");
          return;
        }
      }
    }
  }
  printf("NO\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
