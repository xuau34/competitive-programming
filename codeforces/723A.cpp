#include <bits/stdc++.h>
using namespace std;
int T, M, Q, arr[4];
double N;
void ini(void){
  for(int i = 0; i < 3; ++i) scanf("%d", arr + i);
  sort(arr, arr + 3);
}

void sol(void){
  printf("%d\n", arr[2] - arr[0]);  //解法錯。並不是最遠兩點之中點，而是其一不動。
}

int main(void){
  int i, j;

  ini();

  sol();

}
