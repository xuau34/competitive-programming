#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T, N, M, Q;
pair<int, int> cash[15], dp[200000];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d %d", &cash[i].first, &cash[i].second);
  }
  M = 0;
}

void sol(void){
  memset(dp, -1, sizeof(dp));
  dp[0].first = 0;
  for(int i = 0; i< N; ++i){
    //printf("cash[%d] = (%d, %d)\n", i, cash[i].first, cash[i].second);
    //dp[0] = cash[i].first;
    if( !cash[i].first ) continue;
    for(int j = cash[i].second; j <= T; ++j){
      if( dp[ j ].first >= 0 ) continue;
      Q = j - cash[i].second;
      if( dp[ Q ].first >= 0 ){
        if( dp[ Q ].second != i ) dp[j].first = cash[i].first - 1;
        else if(dp[Q].first) dp[j].first = dp[Q].first - 1;
        else continue;
        dp[j].second = i;
        M = max(M, j);
        //printf("dp[%d] = %d,%d\n", j, dp[j].first, dp[j].second);
      }
    }
    /*
    for(int j = M; j >= 0; --j){
      if(!dp[j]) continue;
      for(int k = 0, s = j + cash[i].second; k < cash[i].first && s <= T; ++k, s += cash[i].second){
        dp[s] = 1;
        //printf("dp[%d] = 1\n", s);
        M = max(M, s);
      }
    }
    */
  }
  //if(x) printf("\n");
  printf("%d\n", M);
}

int main(void){
  int i, j;
  while( scanf("%d", &T) == 1 ){
    ini();
    sol();
    //x = 1;
  }
}
