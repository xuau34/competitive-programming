/*
  WA
 */
#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

inline bool check(int x){
  while(x){
    int y = x % 10;
    if(y != 1 && y != 0) return true;
    x /= 10;
  }
  return false;
}

void sol(void){
  vector<int> ans;
  for(int i = N, j = N; i > 0; --i){
    if( check(i) ) continue;
    ans.insert( ans.begin(), j / i, i);
    i = (j %= i) + 1;
  }
  printf("%d\n", ans.size());
  for(int i: ans) printf("%d ", i);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
