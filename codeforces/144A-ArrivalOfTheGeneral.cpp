#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, arr[105], MA, MI;
  scanf("%d", &N);
  for(i = MA = MI = 0; i < N; i++){
    scanf("%d", arr + i);
    if(arr[i] > arr[MA]) MA = i;
    else if(arr[i] <= arr[MI]) MI = i;
  }
  if(MA < MI) printf("%d\n", MA + N - 1 - MI);
  else printf("%d\n", MA - 1 + N - 1 - MI);
}
