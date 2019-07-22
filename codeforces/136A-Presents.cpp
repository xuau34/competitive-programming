#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, arr[105], ans[105];
  scanf("%d", &N);
  for(i = 1; i <= N; i++){
    scanf("%d", arr + i);
    ans[arr[i]] = i;
  }
  for(i = 1; i <= N; i++){
    printf("%d", ans[i]);
    if(i == N) printf("\n");
    else printf(" ");
  }
}
