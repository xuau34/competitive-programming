#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;

void ini(void){
  cin >> N >> M;
  T = M / N;
  Q = (T + 1) * N;
  T *= N;
}

void sol(void){
  cout << T << ", " << Q << endl;
  long long ans = 0;
  while(M > T){
    M -= __gcd(N, Q - M);
    ++ans;
  }
  ans += __gcd(N, M) * 
}

int main(void){

  ini();

  sol();

}
