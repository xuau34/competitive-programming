#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, node[100005];

int main(void){
  int i, j, k;
  scanf("%d", &T);
  while(T--){
    memset(node, 0, sizeof(node));
    scanf("%d", &N);
    for(i = 1; i < N; i++){
      scanf("%d %d", &j, &k);
      node[j]++;
      node[k]++;
    }
    for(i = 1, j = 0; i <= N; i++) if(node[i] == 1) j++;
    printf("%d\n", (N < 3)? j - 1: j);
  }
}
