#include <iostream>
using namespace std;
int T, N, M, Q, arr[105][105];

void ini(void){
  int x, y;
  for(int i = 1; i <= N; ++i) for(int j = 1; j <= N; ++j) arr[i][j] = 10000;
  for(int i = 1; i <= N; ++i){
    scanf("%d", &M);
    arr[i][i] = 0;
    for(int j = 0; j < M; ++j){
      scanf("%d%d", &x, &y);
      arr[i][x] = min(arr[i][x], y);
    }
  }
}

void sol(void){
  int sum = 2147483647, temp, ans, Mx = 0;
  for(int k = 1; k <= N; ++k)
    for(int i = 1; i <= N; ++i)
      for(int j = 1; j <= N; ++j) arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
  for(int i = 1; i <= N; ++i){
    temp = 0;
    for(int j = 1; j <= N; ++j) temp += arr[i][j];
    if(sum > temp) sum = temp, ans = i;
  }
  for(int i = 1; i <= N; ++i) Mx = max(Mx, arr[ans][i]);
  printf("%d %d\n", ans, Mx);
}

int main(void){
  int i, j;
  while( scanf("%d", &N) && N ){
    ini();
    sol();
  }
}
