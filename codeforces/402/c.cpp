#include <bits/stdc++.h>
using namespace std;
int T, N, K, Q, now[200005], after[200005], dp0[200005];
int dp1[200005];

void ini(void){
  int i;
  scanf("%d %d", &N, &K);
  for(i = 1; i <= N; i++){
    scanf("%d", now + i);
  }
  for(i = 1; i <= N; i++){
    scanf("%d", after + i);
  }
}

void sol(void){
  int i, j;
  dp0[0] = after[1];
  dp0[1] = now[1];
  dp0[2] = 2007483647;
  for(i = 2; i <= N; i++){
    for(j = 0; j <= i; j++){
      dp1[j] = min(((!j)? 2007483647: dp0[j - 1] + now[i]), dp0[j] + after[i]);
      //printf("%d: dp0[%d] = %d => dp1[%d] = %d\n", i, j, dp0[j], j, dp1[j]);
    }
    for(j = 0; j <= i; j++){
      dp0[j] = dp1[j];
    }
    dp0[i + 1] = 2007483647;
  }
  for(i = K, j = 2007483647; i <= N; i++){
    j = (j > dp0[i])? dp0[i]: j;
  }
  printf("%d\n", j);
}

int main(void){
  int i, j;

  ini();

  sol();

}
