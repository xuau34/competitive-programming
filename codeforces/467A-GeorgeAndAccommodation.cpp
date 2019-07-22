#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, k, ans;
  scanf("%d", &N);
  for(i = ans = 0; i < N; i++){
    scanf("%d %d", &j, &k);
    if(k - j > 1) ans++;
  }
  printf("%d\n", ans);
}
