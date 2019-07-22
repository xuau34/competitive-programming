#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, arr[55], ans = 20000;
  scanf("%d %d", &N, &T);
  for(i = 0; i < T; i++) scanf("%d", arr + i);
  sort(arr, arr + T);
  for(i = N - 1; i < T; i++){
    ans = (ans > (arr[i] - arr[i - N + 1]))? (arr[i] - arr[i - N + 1]): ans;
  }
  printf("%d\n", ans);
}
