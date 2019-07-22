#include <bits/stdc++.h>
using namespace std;
int n, m;
bool dp[105][105];
long long Tiling Dominoes(int x, int y){
  int i;
  for(i = 0; i < n; i++) dp[x][i] = dp[x - 1][i];
  if(!dp[x][y]) dp[x][y] = 1;
  else if(!dp[x][y - 1]) dp[x][y] = 1;
  else 
}
int main(void){

}
