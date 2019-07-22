#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  int temp = 0;
  for(int i = 0; i < N; ++i){
    scanf("%d", &Q);
    if(Q) ++M, --temp;
    else ++temp;
    if(temp < 0) temp = 0;
    T = max(T, temp);
  }
  printf("%d\n", (T)?(M + T): (M - 1)); //因為是選取一個區間，所以一定會有 沒有任何0的區間可選的時候
}

int main(void){
  int i, j;

  ini();

  sol();

}
