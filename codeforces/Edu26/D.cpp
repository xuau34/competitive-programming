#include <bits/stdc++.h>
using namespace std;
int T, N, M, arr[205][2], dp[4005][4005];
long long Q;

void ini(void){
  scanf("%d%d", &N, &M);
  int a, b;
  for(int i = 0; i < N; ++i){
    scanf("%lld", &Q);
    a = b = 0;
    while(Q && !(Q & 1)){
      ++a, Q >>= 1;
    }
    while(Q && Q % 5 == 0){
      ++b, Q /= 5;
    }
    arr[i][0] = a, arr[i][1] = b;
  }
}

void sol(void){
  memset(dp, -1, sizeof(dp));
  int a = arr[0][0], b = arr[0][1];
  int A = a, B = b;
  dp[0][0] = 0, dp[a][b] = 1;
  for(int n = 1; n < N; ++n){
    printf("arr[%d] = (%d, %d): A = %d, B = %d\n", n, arr[n][0], arr[n][1], a, b, A, B);
    for(int i = A; i >= 0; --i){
      for(int j = B; j >= 0; --j){
        if(dp[i][j] >= 0 && dp[i][j] + 1 <= M){
          int x = i + arr[n][0], y = j + arr[n][1];
          dp[x][y] = (dp[x][y] >= 0)? min( dp[x][y], dp[i][j] + 1): dp[i][j] + 1;
          //printf("dp[%d][%d]\n", x, y);
          if(min(x, y) > min(a, b)) a = x, b = y;
          A = max(A, x), B = max(B, y);
        }
      }
    }
    //printf("arr[%d] = (%d, %d) => (%d, %d)\n", n, arr[n][0], arr[n][1], a, b);
  }
  printf("%d\n", min(a, b));
}

int main(void){
  int i, j;

  ini();

  sol();

}
