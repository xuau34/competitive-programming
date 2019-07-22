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

    if(no1s <= arr[1]){
      ans += no1n;
      arr[1] -= no1s;
    }else{
      i = no1s - arr[1];
      if(i & 1 || no1n <= (i>>1)){
        printf("tsan\n");
        continue;
      }else{
        ans += (no1n - (i>>1));
        arr[1] = 0;
      }
    }
    //cout<<ans<<" ";

    if(arr[1] & 1){
      printf("tsan\n");
      continue;
    }else ans += (arr[1] >> 1);
    //cout<<ans<<" ";

    printf("%d\n", ans + arr[0]);
  }
}
