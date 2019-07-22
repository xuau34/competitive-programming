#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j, x, y, arr[10][10];
  for(i = 1; i < 6; i++){
    for(j = 1; j < 6; j++){
      scanf("%d", arr[i] + j);
      if(arr[i][j]){
        x = i;
        y = j;
      }
    }
  }
  x = abs(x - 3);
  y = abs(y - 3);
  printf("%d\n", x + y);
}
