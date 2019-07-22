#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long ans;
int main(void){
  int i, j, p;
  scanf("%d %d", &N, &M);
  for(i = 0, p = 1; i < M; i++){
    scanf("%d", &j);
    if(j < p){
      ans += N - p + j;
    }else if(j > p){
      ans += j - p;
    }
    p = j;
  }
  printf("%I64d\n", ans);
}
