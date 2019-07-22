#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[505], to[505];
pair<int, int> cost[505][2];

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
  cost[0][0].first = cost[0][0].second = cost[0][1].first = 1;
  cost[0][1].second = 1;
}

void sol(void){
  pair<int, int> pii;
  for(int i = 1; i < N; ++i){
    for(int j = i - 1; j >= 0; --j){
      if(arr[j] != arr[i]) continue;

      for(int k = j; k < i; ++k){
        printf("j = %d ", j);
        if( (pii.second = cost[i - 1][1].second - cost[j][1].second) >= 0 ){
          pii.first = cost[i - 1][1].first - cost[j][1].first;

          cost[i][1] = min( cost[i][1], make_pair( pii.first + cost[j - 1][1].first, pii.second + cost[j - 1][1].second ) );
        }/*else if( (pii.second = cost[i - 1][1].second - cost[j][1].second) >= 0 ){
          pii.first = cost[i - 1][1].first - cost[j][1].first;

          cost[i] = min( cost[i][1], make_pair( pii.first + cost[j - 1].first, pii.second + cost[j - 1].second ) );
        }*/
      }
    }
    if( !cost[i][0].first ){
      cost[i][0] = make_pair( cost[i - 1][0].first + 1, cost[i - 1][0].second + 1 );
    }
    printf("%d: cost: (%d, %d)\n", i, cost[i][0].first, cost[i][1].second);
    //printf("dp[%d] = (%d, %d, %d)\n", i, dp[i][0], dp[i][1], dp[i][2]);
  }
  //printf("%d\n", dp[N -1][0] + dp[N - 1][1]);
}

int main(void){
  int i, j;

  ini();

  sol();

}
