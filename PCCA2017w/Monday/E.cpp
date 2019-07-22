#include <bits/stdc++.h>
using namespace std;
vector<int> t;
int dp[2][5005];
int SG(int x){
  if(dp[0][x] != -1) return dp[0][x];
  set<int> s;
  int i, j, a, b;
  for(i = j = 0; i < x; i++){
    a = b = 0;
    if(i > 1){
      a = SG(i - 1);
      if(dp[1][x] == -1) dp[1][x] = dp[1][i - 1] + 1;
      else dp[1][x] = (dp[1][x] > dp[1][i - 1] + 1)? dp[1][i - 1] + 1: dp[1][x];
    }
    if(i + 2 < x){
      b = SG(x - i - 2);
      if(dp[1][x] == -1) dp[1][x] = dp[1][i - 1] + 1;
      else dp[1][x] = (dp[1][x] > dp[1][i - 1] + 1)? dp[1][i - 1] + 1: dp[1][x];
    }
    s.insert(a ^ b);
  }
  while(s.count(j) != 0) j++;
  return dp[0][x] = j;
}
int main(void){
  int i, j, ans, move;
  char str[5005];
  memset(dp, -1, sizeof(dp));
  scanf("%s", str);
  for(i = 1, j = dp[0][0] = dp[1][0] = move = 0; i < strlen(str); i++){
    if(str[i - 1] == str[i + 1]){
      j++;
      cout<<j<<endl;
    }else if(j){
      t.push_back(j);
      j = 0;
    }
  }
  for(i = 1; i < 40; i++) cout<<SG(i)<<" ";
  cout<<endl;
  for(i = 0; i < t.size(); i++){ cout<<t[i]<<" ";
    if(i) ans ^= SG(t[i]);
    else ans = SG(t[i]);
    move += dp[1][t[i]];
  }
  if(ans) printf("First\n%d\n", move);
  else printf("Second\n");
}
