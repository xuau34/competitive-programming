#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  cin >> N >> M;
}

void sol(void){
  if( M % N ){
    cout << -1 << endl;
    return;
  }
  int x = 0, a = M / N;
  while( a && a % 2 == 0 ){
    a >>= 1, ++x;
  }
  while( a && a % 3 == 0 ){
    a /= 3, ++x;
  }
  if(a > 1) cout << -1 << endl;
  else cout << x <<endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
