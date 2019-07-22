#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
pair<int, int> arr[1005];
int main(void){
  int i, j, s;
  scanf("%d %d", &s, &N);
  for(i = 0; i < N; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
  sort(arr, arr+N);
  for(i = 0; i < N; i++){
    if(s > arr[i].first) s+= arr[i].second;
    else{
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}
