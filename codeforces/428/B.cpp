#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[10005];

void ini(void){
  scanf("%d%d", &T, &M), N = T << 1;
  for(int i = 0; i < M; ++i){
    scanf("%d", arr + i);
    if(arr[i] & 1) ++Q, --arr[i];
  }
}

bool sol(void){
  while(Q && T) --Q, --T, ++N;
  int y;
  for(int i = 0; i < M; ++i){
    y = min(T, arr[i] >> 2);
    T -= y;
    arr[i] -= y << 2;
    //printf(" => %d", x);

    y = min(N, arr[i] >> 1);
    N -= y;
    arr[i] -= y << 1;
    //printf(" => %d", x);

    //printf(" : %d\n", Q);
    //printf("arr[%d] = %d, %d, %d, Q = %d\n", i, arr[i], T, N, Q);
  }
  for(int i = 0; i < M; ++i){
    y = min(T, arr[i] >> 1);
    T -= y;
    arr[i] -= y << 1;
    N += y;
    
    Q += arr[i];
    //printf("arr[%d] = %d, %d, %d, Q = %d\n", i, arr[i], T, N, Q);
  }
  //printf("%d, %d\n", T, N);
  if(Q <= (T << 1) + N) return true;
  return false;
}

int main(void){
  int i, j;

  ini();

  if( sol() ) printf("YES\n");
  else printf("NO\n");

}
