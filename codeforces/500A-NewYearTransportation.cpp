#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
int arr[50005];
int main(void){
  int i, j;
  scanf("%d %d", &N, &T);
  for(i = j = 1; i < N; i++) scanf("%d", arr + i);
  while(j < N && j != T){
    j += arr[j];
  }
  if(j == T) printf("YES\n");
  else printf("NO\n");
}
