#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
int arr[4];
int main(void){
  int i, j, ans = 0;
  scanf("%d %d %d %d", arr, arr+1, arr+2, arr+3);
  for(i = 0; i < 4; i++){
    for(j = i + 1; arr[i] > 0 && j < 4; j++){
      if(arr[j] == arr[i]){
        arr[j] = 0;
        ans++;
      }
    }
  }
  printf("%d\n", ans);
}
