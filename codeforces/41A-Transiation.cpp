#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j;
  string A, B;
  cin>>A>>B;
  reverse(A.begin(), A.end());
  for(i = 0, j = A.length(); i < j; i++){
    if(A[i] != B[i]){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}
