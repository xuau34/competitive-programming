#include <cstdio>
#include <algorithm>
using namespace std;
int T, N, M, Q;

void sol(void){
  scanf("%d", &N);
  long long x =  N / 3 ;
  printf("%lld\n", ( (3 + x * 3) * x ) / 2);
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    sol();
  }
}
