#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool arr[100005];
void ini(void){
  scanf("%d", &N);
}

void sol(void){
  for(int i = 2; i <= N + 1; ++i){
    if( !arr[i] ){
      M = i << 1;
      while( M <= N + 1){
        arr[M] = 1;
        M += i;
      }
    }
  }
  printf("%d\n", (N > 2)? 2: 1);
  for(int i = 2; i <= N + 1; ++i) printf("%d ", arr[i] + 1);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
