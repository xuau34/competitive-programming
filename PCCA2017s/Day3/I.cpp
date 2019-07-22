#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005];
long long dp[100005][2];
void ini(void){
  cin >> N;
  for(int i = 0; i < N; ++i){
    cin >> Q;
    ++arr[Q];
    M = max(M, Q);
  }
}

void sol(void){
  for(int i = 1; i <= M; ++i){
    dp[i][1] = dp[i - 1][0] + i * arr[i];
    dp[i][0] = dp[i - 1][1];
  }
  cout << max( dp[M][0], dp[M][1] ) << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
