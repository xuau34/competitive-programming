#include <bits/stdc++.h>
using namespace std;
int T, N, Q;

void ini(void){

}

int f(int i, int x, int M){
  if(x == 0 || x == i) return 1;
  if(i < x) return 0;
  long long X = f(i - 1, x - 1, M) + f(i - 1, x, M);
  if(X % M == 0) return 0;
  //printf("f(%d, %d, %d) = %lld\n", i, x, M, X);
  return X;
}

void sol(void){

}

int main(void){

  ini();
  int x, y, z; 
  while(~scanf("%d%d%d", &x, &y, &z)){
    for(int i = 0; i <= x; ++i){
      cout << f(i, y, z) << endl;
    }
  }

}
