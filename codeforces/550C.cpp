#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[105];
bool dp[1000];
void ini(void){
  scanf("%s", str);
}

void sol(void){
  for(int i = 0, j = strlen(str); i < j; ++i){
    int x = str[i] - '0';
    for(int k = 99; k >= 0; --k) if(dp[k]) dp[10 * k + x] = true;
    dp[x] = true;
  }
  for(int i = 0; i < 1000; i += 8)
    if(dp[i]){
      printf("YES\n%d\n", i);
      return;
    }
  printf("NO\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
