#include <bits/stdc++.h>
using namespace std;
int T, N, M;
bool prim[100010];

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  int i, j, k;
  for(i = 2; i <= N + 1; i++){
    if(prim[i]) continue;
    j = i + i;
    while(j <= N + 1){
      prim[j] = 1;
      j += i;
    }
  }
  printf("%d\n", (N > 2)? 2: 1);
  for(i = 2; i <= N + 1; i++){
    printf("%d ", prim[i] + 1);
  }
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
