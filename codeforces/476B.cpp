#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[15];
void ini(void){
  scanf("%s", str);
  for(int i = 0, j = strlen(str); i < j; ++i) M += (str[i] == '+')? 1: -1;
  //cout << M + 10 << endl;
}

void sol(void){
  int dp[25], temp[25];
  memset(dp, 0, sizeof(dp));
  scanf("%s", str);
  dp[10] = 1;
  for(int i = 0, n = strlen(str); i < n; ++i){
    memset(temp, 0, sizeof(temp));
    if(str[i] == '+' || str[i] == '?')
      for(int j = 0; j < 25; ++j) temp[j + 1] = dp[j];
    if(str[i] == '-' || str[i] == '?')
      for(int j = 1; j < 25; ++j) temp[j - 1] += dp[j];
    memcpy(dp, temp, sizeof(dp));
    //for(int j = 0; j < 25; ++j) printf("(%d,%d) ", j, dp[j]);
    //printf("\n");
  }
  long long sum = 0;
  for(int i = 0; i < 25; ++i) sum += dp[i];
  printf("%.10lf\n", (double)dp[M + 10] / sum);
}

int main(void){
  int i, j;

  ini();

  sol();

}
