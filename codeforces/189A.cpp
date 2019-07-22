#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[5], dp[4005];
bool v[4005];
void ini(void){
  scanf("%d", &T);
  for(int i = 0; i < 3; ++i) scanf("%d", arr + i);
  v[0] = 1;
}

void sol(void){
  for(int i = 0; i < 3; ++i){
    for(int j = 0; j + arr[i] <= T; ++j){
      if(v[j]){
        dp[j + arr[i]] = max(dp[j + arr[i]], dp[j] + 1);
        v[j + arr[i]] = 1;  //這裡邊界沒處理好，Bus error:10
      }
    }
  }
  printf("%d\n", dp[T]);
}

int main(void){
  int i, j;

  ini();

  sol();

}
