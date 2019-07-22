#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j;
  char str[55];
  scanf("%d %d", &N, &T);
  scanf("%s", str);
  while(T--){
    for(i = 1; i < N; i++){
      if(str[i - 1] == 'B' && str[i] == 'G'){
        str[i - 1] = 'G';
        str[i] = 'B';
        i++;
      }
    }
  }
  printf("%s\n", str);
}
