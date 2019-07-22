#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool arr[105];
int main(void){
  int i, j;
  scanf("%d", &N);
  for(i = M = 0; i < 2; i++){
    scanf("%d", &T);
    while(T--){
      scanf("%d", &j);
      if(!arr[j]){
        arr[j] = 1;
        M++;
      }
    }
  }
  if(M == N) printf("I become the guy.\n");
  else printf("Oh, my keyboard!\n");
}
