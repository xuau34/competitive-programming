#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[5005];

void ini(void){
  scanf("%d%d%d", &N, &M, &Q), --M;
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
}

void sol(void){
  long long dp[5005], temp[5005], mx = 0;
  memset(dp, 0, sizeof(dp));
  while(Q--){
    memset(temp, 0, sizeof(temp));
    for(int i = M; i < N; ++i){
      for(int j = M;)
    }
    memcpy(dp, temp, sizeof(dp));
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
