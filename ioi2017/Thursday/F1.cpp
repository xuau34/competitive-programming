/*
   此以deg嘗試解這題，
   但因deg總和無法分辨是由什麼樣的deg的節點組合而來的
   因此吃wa
*/
#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[1005];

int main(void){
  int i, j, ans, no1n, no1s;
  scanf("%d", &T);
  while(T--){
    memset(arr, 0, sizeof(arr));
    scanf("%d", &N);
    for(i = no1n = no1s = ans = 0; i < N; i++){
      scanf("%d", &j);
      arr[j]++;
      if(j > 1){
        no1n++;
        no1s += j;
      }
    }

    if((no1n && !arr[1]) || (no1s + arr[1]) & 1){
      printf("tsan\n");
      continue;
    }

    i = (no1s + arr[1]) >> 1;
    //cout<<i<<" ";

    if(N < i){
      printf("tsan\n");
      continue;
    }else ans += N - arr[0] - i;
    //cout<<ans<<" ";

    printf("%d\n", ans + arr[0]);
  }
}
