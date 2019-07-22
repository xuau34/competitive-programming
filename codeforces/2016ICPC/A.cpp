#include <cstdio>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  bool ans = 0;
  while(N--){
    scanf("%d%d", &M, &Q);
    int x = Q / M;
    ans ^= (Q != M * x + x);
    //printf("%d ", ans);
  }
  printf("%d\n", (ans)? 1: 2);
}

int main(void){
  freopen("powers.in", "r", stdin);

  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
