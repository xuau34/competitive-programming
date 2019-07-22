#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j;
  scanf("%d", &i);
  for(++i;; i++){
    j = i;
    bool arr[10] = {0};
    while(j > 0 && !arr[j % 10]){
      arr[j % 10] = 1;
      j/=10;
    }
    if(j == 0){
      printf("%d\n", i);
      return 0;
    }
  }
}
