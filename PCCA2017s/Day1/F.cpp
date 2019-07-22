#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool arr[100005];

void ini(void){
  scanf("%d", &N);
  scanf("%d", &M);
  arr[0] = M & 1;
  for(int i = 1; i < N; ++i){
    scanf("%d", &Q);
    M = __gcd(M, Q);
    arr[i] = Q & 1;
  }
}

void sol(void){
  if(M > 1){
    printf("YES\n0\n");
    return;
  }
  M = 0;
  for(int i = 1; i < N; ++i){
    if(arr[i - 1]){
      if( arr[i] ) ++M;
      else M += 2;
      arr[i] = 0;
    }
  }
  if(arr[N - 1]) M += 2;
  printf("YES\n%d\n", M);
}

int main(void){
  int i, j;

  ini();

  sol();

}
