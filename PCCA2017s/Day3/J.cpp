#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;

void ini(void){
  cin >> N;
}

void sol(void){
  while(N){
    M += N & 1;
    N >>= 1;
  }
  cout << M << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
