#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool prime[1000005];
void ini(void){
  scanf("%d", &N);
  for(int i = 2; i < 1000005; ++i){
    if(prime[i]) continue;
    for(int j = i << 1; j < 1000005; j += i) prime[j] = 1;
  }
}

void sol(void){
  for(int i = 1; i <= 1000; ++i){
    if(prime[i * N + 1]){
      printf("%d\n", i);
      return;
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
