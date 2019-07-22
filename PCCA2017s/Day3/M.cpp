#include <bits/stdc++.h>
using namespace std;
long long  T, N, M, Q;

void ini(void){
  cin >> N;
}

void sol(void){
  long long ans = ( (N + 1) >> 1 ) * ( (N & 1)? -1: 1 );
  cout << ans<< endl;

}

int main(void){
  int i, j;

  ini();

  sol();

}
