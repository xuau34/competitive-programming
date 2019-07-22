#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, pre[(int)2e5+10];

void ini(void){
  scanf("%d%d%d", &N, &M, pre);
  for(int i = 1, j; i < N; ++i) scanf("%d", &j), pre[i] = j + pre[i - 1];
}

void sol(void){
  int ans = 0, sum = pre[M - 1], temp;
  for(int i = 1; i + M - 1 < N; ++i){
    temp = pre[i + M - 1] - pre[i - 1];
    //printf("pre[%d] - pre[%d] = %d - %d vs %d\n", i + M - 1, i - 1, pre[i + M - 1], pre[i - 1], sum);
    if(temp < sum) ans = i, sum = temp;
  }
  printf("%d\n", ans + 1);
}

int main(void){
  int i, j;

  ini();

  sol();

}
