#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[1005];

void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
  sort(arr, arr + N);
}

void sol(void){
  for(int i = 0; i < N; ++i){
    Q = max(Q, arr[i] - arr[i - 1]);
  }
  Q = max(Q, max(arr[0] - 0, M - arr[N - 1]) * 2);
  printf("%.10lf\n", (double)Q / 2);
}

int main(void){
  int i, j;

  ini();

  sol();

}
