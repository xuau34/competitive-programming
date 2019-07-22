#include <bits/stdc++.h>
using namespace std;
int T, N, M, X, A, arr[20][100005], dp[20][100005];
deque<int> deq;

void ini(void){
  int i, j;
  scanf("%d %d %d %d", &N, &M, &X, &A);
  for(i = 1; i <= N; i++){
    for(j = 1; j <= M; j++){
      scanf("%d", arr[i] + j);
      arr[i][j] += arr[i][j - 1];
    }
  }
}

int value(int x, int dir, int fl){
  if(dir > 0) return arr[fl][x] + dp[fl - 1][x];
  else return arr[fl][M] - arr[fl][x - 1] + dp[fl - 1][x];
}

void ready(int x, int dir, int fl){
  int i, j, k;
  if(dir > 0) while(!deq.empty() && deq.front() < x) deq.pop_front();
  else while(!deq.empty() && deq.front() > x) deq.pop_front();

  i = (deq.empty())? x: deq.back() + dir;

  for(; i != x + (A + 1) * dir && i > 0 && i <= M; i += dir){
    j = value(i, dir, fl);

    while(!deq.empty()){
      k = value(deq.back(), dir, fl);
      if(j > k) deq.pop_back();
      else break;
    }

    deq.push_back(i);
  }
}

void sol(void){
  int i, j, L = X, R = X;

  for(i = 1; i <= N; i++){
    for(j = max(1, L - A); j < L; j++) dp[i - 1][j] = -1250000005;
    for(j = min(M, R + A); j > R; j--) dp[i - 1][j] = -1250000005;
    dp[0][X] = 0;
    L = max(1, L - A);
    R = min(M, R + A);

    for(deq.clear(), j = L; j <= R; j++){
      ready(j, 1, i);
      dp[i][j] = value(deq.front(), 1, i) - arr[i][j - 1];
    }
    for(deq.clear(), j = R; j >= L; j--){
      ready(j, -1, i);
      dp[i][j] = max(dp[i][j], value(deq.front(), -1, i) - (arr[i][M] - arr[i][j]));
    }

  }

  for(i = L, j = dp[N][L + 1]; i <= R; i++){
    if(dp[N][i] > j) j = dp[N][i];
  }
  printf("%d\n", j);
}

int main(void){

  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }

}
