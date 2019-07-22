#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005];

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
}

void sol(void){
  int ans = 1;
  for(int i = 0, j = 0, prelen = 0; j < N; i = ++j){
    while(arr[j + 1] > arr[j]) ++j;
    //printf("(%d, %d) => ", i, j);
    if( (i > 0 && arr[i + 1] - arr[i - 1] > 1) || (i > 1 && arr[i] - arr[i - 2] > 1)){
      ans = max(ans, prelen + 1 + j - i);
      //printf("ans = %d ", ans);
    }
    prelen = j - i + 1;
    ans = max(ans, min(prelen + 1, N) );
    //printf("prelen = %d, ans = %d\n", prelen, ans);
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
