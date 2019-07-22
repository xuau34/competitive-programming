#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[3000005];
char ans[3000005];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < 3000005; ++i) ans[i] = 'a';
}

void sol(void){
  char str[1000005];
  int l;
  for(int i = 0; i < N; ++i){
    scanf("%s%d", str, &M);
    l = strlen(str);
    for(int j = 0; j < M; ++j){
      scanf("%d", &Q), --Q;
      if( arr[Q] < l ){
        for(int k = arr[Q]; k < l; ++k){
          ans[Q + k] = str[k];
          arr[Q + k] = max(l - k, arr[Q + k]);
        }
        arr[Q] = l;
      }
  //printf("%s\n", ans);
    }
    T = max(T, Q + l);
  }
  /*
  for(int i = 0; i < T; ++i){
    if(arr[i] == 0) ans[i] = 'a';
    else i += arr[i];
  }
  */
  ans[T] = 0;
  printf("%s\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
