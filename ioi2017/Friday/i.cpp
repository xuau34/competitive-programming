#include <bits/stdc++.h>
using namespace std;
int T, N, M, X, A, Q, arr[20][100005], dp[20][100005];
deque<pair<int, int> > deq;
int main(void){
  int i, j, k, l;
  pair<int, int> pii;
  scanf("%d", &T);
  while(T--){
    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));
    scanf("%d %d %d %d", &N, &M, &X, &A);
    for(i = 1; i <= N; i++){
      for(j = 1; j <= M; j++){
        scanf("%d", arr[i] + j);
      }
    }
    for(j = 1; j <= M; j++){
      if(j != X) dp[0][j] = -2147483640;
    }
    for(i = 1; i <= N; i++){
      for(j = 1, k = l = 0; j <= N; j++){
        k += arr[i][j - 1];

        if(!deq.empty() && j - A > deq.front().second) deq.pop_front();

        while(deq.empty() || (deq.back().second < j + A && deq.back().second + 1 <= N)){
          if(deq.empty()){
            pii.second = j;
            pii.first = arr[i][j] + dp[i - 1][j];
            l = arr[i][j];
          }else{
            l += arr[i][deq.back().second + 1];
            pii.second = deq.back().second + 1;
            pii.first = l + dp[i - 1][pii.second];
          }
          while(!deq.empty() && deq.back().first < pii.first) deq.pop_back();
          deq.push_back(pii);
          printf("(%d, %d) ", pii.first, pii.second);
        }

        dp[i][j] = deq.front().first - k;
        printf("\n dp[%d][%d] = %d - %d = %d\n", i, j, deq.front().first, k, dp[i][j]);
      }

      for(j = N, k = l = 0; j; j--){
        k += arr[i][j + 1];

        if(!deq.empty() && j + A < deq.front().second) deq.pop_front();

        while(deq.empty() || (deq.back().second > j - A && deq.back().second - 1 > 0)){
          if(deq.empty()){
            pii.second = j;
            pii.first = arr[i][j] + dp[i - 1][j];
            l = arr[i][j];
          }else{
            l += arr[i][deq.back().second - 1];
            pii.second = deq.back().second - 1;
            pii.first = l + dp[i - 1][pii.second];
          }
          while(!deq.empty() && deq.back().first < pii.first) deq.pop_back();
          deq.push_back(pii);
          printf("(%d, %d) ", pii.first, pii.second);
        }

        printf("\n dp[%d][%d] = %d vs %d - %d = ", i, j, dp[i][j], deq.front().first, k);
        dp[i][j] = (dp[i][j] < deq.front().first - k)? deq.front().first - k: dp[i][j];
        printf("%d\n", dp[i][j]);
      }
      scanf("%d", &j);
      deq.clear();
    }
  }
}
