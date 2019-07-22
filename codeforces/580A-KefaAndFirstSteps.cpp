#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, jj, temp, ans;
  scanf("%d", &N);
  scanf("%d", &j);
  for(i = temp = 1, ans = 0; i < N; i++){
    scanf("%d", &jj);
    if(j <= jj) temp++;
    else{
      ans = max(ans, temp);
      temp = 1;
    }
    j = jj;
  }
  printf("%d\n", max(ans, temp));
}
