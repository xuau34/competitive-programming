#include <cstdio>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  int ans = 0;
  while(N > 0){
    ans += N & 1;
    N >>= 1;
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
