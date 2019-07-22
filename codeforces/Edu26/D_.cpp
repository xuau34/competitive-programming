/*  AC - 156ms, 10100KB
    dp[取了多少][roundness][0] - 2的數量
                           [1] - 5的數量
    由於2和5的數量都覺得很重要，
    又無法dp[2的數量][5的數量] = roundness (MLE)
    因此將能取越多越好 => 必定只會剩下2 或是5
    如此轉移的障礙就消失惹。
 */

#include <bits/stdc++.h>
using namespace std;
int T, N, M, dp[205][5005][2];
long long Q;

void ini(void){
  scanf("%d%d", &N, &M);
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = dp[0][0][1] = 0;
}

void sol(void){
  int a, b, A, B, C;
  for(int i = 0; i < N; ++i){
    scanf("%lld", &Q);
    a = b = 0;
    while(Q && !(Q & 1)) ++a, Q >>= 1;
    while(Q && Q % 5 == 0) ++b, Q /= 5;

    for(int k = min(i, M); k >= 0; --k){
      for(int j = 0; j < 5005; ++j){
        if(dp[k][j][0] >= 0){
          A = a + dp[k][j][0], B = b;
          C = min(A, B);
          A -= C, B -= C;
          C += j;
          dp[k + 1][C][0] = max(dp[k + 1][C][0], A);
          dp[k + 1][C][1] = max(dp[k + 1][C][1], B);
        }

        if(dp[k][j][1] >= 0){
          A = a, B = b + dp[k][j][1];
          C = min(A, B);
          A -= C, B -= C;
          C += j;
          dp[k + 1][C][0] = max(dp[k + 1][C][0], A);
          dp[k + 1][C][1] = max(dp[k + 1][C][1], B);
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < 5005; ++i){
    if(dp[M][i][0] >= 0 || dp[M][i][1] >= 0) ans = max(ans, i);
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
