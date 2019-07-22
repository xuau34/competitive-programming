#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;

void ini(void){
  cin >> N >> M;
}

void sol(void){
  Q = (N + 1) >> 1;
  if(M > Q) cout << (M - Q) * 2 << endl;
  else cout << (M * 2) - 1 << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
