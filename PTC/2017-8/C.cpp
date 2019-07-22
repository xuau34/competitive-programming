#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[30];
char str[25];
long long dp[21];
void ini(void){
  memset(arr, 0, sizeof(arr));
  scanf("%s", str);
  N = strlen(str);
  for(int i = 0; i < N; ++i) ++arr[str[i] - 'a'];
}

void sol(void){
  long long ans = 0, ret;
  for(int i = 0; i < N; ++i){
    //printf("str[%d] = %c:\n", i, str[i]);
    for(int j = 0; j + 'a' < str[i]; ++j){
      if(arr[j] == 0) continue;
      ret = dp[N - i - 1];
      //printf("arr[%d] = %d\n", j, arr[j]);
      for(int k = 0; k < 30; ++k) if(arr[k] - ((j == k)? 1: 0) > 1){
        ret /= dp[arr[k] - ((j == k)? 1: 0)];
        //printf("arr[%d] = %d => %lld\n", k, arr[k], ret);
      }
      ans += ret;
    }
    --arr[str[i] - 'a'];
  }
  printf("%lld\n", ans);
}

int main(void){
  int i, j;
  dp[1] = 1;
  for(int i = 2; i < 21; ++i) dp[i] = dp[i - 1] * i;
  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }

}
