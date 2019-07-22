#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, Q, dp[105][105], arr[500];
void ini(void){
  memset(dp, 0x3f, sizeof(dp));
  for(int i = 1; i <= N; i++) dp[i][i] = 0;
  int x, y, z;
  while(M--){
    scanf("%d%d%d", &x, &y, &z);
    dp[x][y] = min( dp[x][y], z );
    dp[y][x] = min( dp[y][x], z );
    /*
    for(i = 0; i <= N; i++){
      for(j = 0; j <= N; j++) printf("%d ", dp[i][j]);
      printf("\n");
    }
    */
  }
}

void sol(void){
  int i, j, k;
  for(k = 1; k <= N; k++){
    for(i = 1; i <= N; i++){
      for(j = 1; j <= N; j++){
        dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
      }
    }
  }
  /*
    for(i = 0; i <= N; i++){
      for(j = 0; j <= N; j++) printf("%d ", dp[i][j]);
      printf("\n");
    }
  */
  printf("%d\n", dp[1][N] );
}

int main(void){
  int i, j;

  while( scanf("%d %d", &N, &M) && N + M ){
    ini();
    sol();
  }
}
