#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <map>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <string.h>
#include <set>
#include <queue>
using namespace std;

const int MOD = 1e9 + 7;
int dp[105][2];

int main ()
{
  //freopen("input.txt","r",stdin);
  int n,k,d;
  cin>>n>>k>>d;
  dp[0][0] = 1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k && j<=i;j++){
      dp[i][1] = (dp[i][1] + dp[i-j][1]) % MOD;
      if(j>=d)
        dp[i][1] = ( dp[i][1] + dp[i-j][0]) % MOD;
      else
        dp[i][0] = (dp[i][0] + dp[i-j][0]) % MOD;
    }
  }
  cout << dp[n][1] << endl;
  return 0;
}
