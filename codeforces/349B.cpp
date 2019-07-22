#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, Q, dp[1000005][10], arr[10], ans[10];

void ini(void){
  dp[0][0] = 1;
  scanf("%d", &N);
  for(int i = 1; i < 10; ++i) scanf("%d", arr + i);
}

inline bool check(int v, int i){
  if(dp[v][0] + 1 == dp[v + arr[i]][0]){
    for(int j = 9, V = v + arr[i]; j > 0; --j){
      if(dp[v][j] + ((j == i)?1: 0) > dp[V][j]) return true;
      else if(dp[v][j] + ((j == i)?1: 0) < dp[V][j]) return false;
    }
    return false;
  }else return dp[v][0] + 1 > dp[v + arr[i]][0];
}

inline bool check_(int v){
  if(dp[v][0] == ans[0]){
    for(int j = 9; j > 0; --j){
      if(dp[v][j] > ans[j]) return true;
      else if(dp[v][j] < ans[j]) return false;  //判斷的部分沒有處理好
    }
    return false;
  }else return dp[v][0] > ans[0];
}

void cover(int v, int i){
  dp[v + arr[i]][0] = dp[v][0] + 1;
  for(int j = 1, V = v + arr[i]; j < 10; ++j){
    dp[V][j] = dp[v][j] + ((i == j)? 1: 0);
  }
}

void cover_(int v){
  ans[0] = dp[v][0];
  for(int j = 1; j < 10; ++j){
    ans[j] = dp[v][j];
  }
}

void sol(void){
  for(int v = 0; v < N; ++v){
    if(!dp[v][0]) continue;
    for(int i = 1; i < 10; ++i){
      if( v + arr[i] <= N && check(v, i) ) cover(v, i); //沒有檢查到出array的部分
    }
    if( check_(v) ){
      cover_(v);
      /*
    printf("%d, %d: ", v, ans[0]);
    for(int i = 1; i < 10; ++i) printf("%d ", ans[i]);
    printf("\n");
    */
    }
  }
  if( check_(N) ) cover_(N);
  if(ans[0] <= 1){
    printf("-1\n");
    return;
  }
  for(int i = 9; i > 0; --i)
    while(ans[i]--) printf("%d", i);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
