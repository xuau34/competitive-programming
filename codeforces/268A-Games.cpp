#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
int arr[105], q[35];
int main(void){
  int i, j;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d %d", &j, q + i);
    arr[j]++;
  }
  for(i = j = 0; i < N; i++){
    j += arr[q[i]];
  }
  printf("%d\n", j);
}
