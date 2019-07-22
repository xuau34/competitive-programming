#include <iostream>
using namespace std;
int T, N, M, D, arr[105];

void ini(void){
  scanf("%d%d%d%d", &N, &M, &T, &D);
}

void sol(void){
  arr[1] = N, arr[T] = M;
  for(int i = T - 1; i > 1; --i){
    arr[i] = arr[i + 1] + D;
  }
  if(arr[2] - arr[1] > D){
    for(int i = 2; i < T; ++i){
      arr[i] = arr[i - 1] + D;
      if(arr[i + 1] - arr[i] <= D) break;
    }
  }
  int ans = 0;
  for(int i = 1; i <= T; ++i){
    ans += arr[i];
    //printf("%d ", arr[i]);
  }
  //printf("\n");
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
