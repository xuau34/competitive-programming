#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;

void ini(void){
  cin >> N >> M;
}

long long f(int a, int b){
  if(b == 0) return 0;
  if(a == __gcd(a, b)) return M / N;
  return 1 + f(a, b - __gcd(a, b));
}

void sol(void){
  cout << f(N, M) << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
