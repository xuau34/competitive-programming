#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n, arr[105], i, sum, s;
  scanf("%d", &n);
  for(i = s = sum = 0; i < n; i++){
    scanf("%d", arr + i);
    sum += arr[i];
  }
  sort(arr, arr + n, greater<int>() );
  for(sum /= 2, i = 0; n-- && s <= sum; i++){
    s += arr[i];
  }
  printf("%d\n", i);
}
