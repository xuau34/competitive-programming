#include <cstdio>
using namespace std;
int T, N, M, Q;

void ini(void){

}

void sol(void){
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", ((n << 1) - 1) * 4 + 2);
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    sol();
  }
}
