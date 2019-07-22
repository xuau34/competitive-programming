#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool r[15], c[15], arr[15][15];
void ini(void){
  scanf("%d %d", &N, &M);
  char str[15];
  for(int i = 0; i < N; ++i){
    scanf("%s", str);
    for(int j = 0; j < M; ++j){
      if(str[j] == 'S'){
        r[i] = c[j] = 1;
      }
    }
  }
}

void sol(void){
  for(int i = 0; i < N; ++i){
    if(!r[i]){
      for(int j = 0; j < M; ++j){
        arr[i][j] = 1;
      }
    }
  }
  for(int j = 0; j < M; ++j){
    if(!c[j]){
      for(int i = 0; i < N; ++i){
        arr[i][j] = 1;
      }
    }
  }
  for(int i = 0; i < N; ++i){
    for(int j =0; j < M; ++j) if(arr[i][j])++T;
  }
  printf("%d\n", T);
}

int main(void){
  int i, j;

  ini();

  sol();

}
