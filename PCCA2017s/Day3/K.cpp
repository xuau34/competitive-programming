#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;

void ini(void){
  cin >> T >> N >> M;
}

void sol(void){
  cout << (long long) ( ceil((double)T / M) * ceil((double)N / M) ) << endl;
  //cout << (T / M + ((T % M)? 1: 0 )) * (N / M +((N % M)? 1: 0)) << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
