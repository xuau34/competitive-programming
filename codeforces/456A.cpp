#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  cin >> N;
}

void sol(void){
  int a, b, A, B;
  bool res = true;
  cin >> a >> b;
  while( --N ){
    cin >> A >> B;
    if( a > A ) res = false;
    if( b < B ) res = false;
    a = A;
    b = B;
  }
  if(res) cout << "Happy Alex" << endl;
  else cout << "Poor Alex" << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
