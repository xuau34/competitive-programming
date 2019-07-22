#include <bits/stdc++.h>
using namespace std;
long long T, x, y, p, q;

void ini(void){
  cin >> x >> y >> p >> q;
}

bool check(int X){
  long long A, B = q * X;
  A = B - y;
  if(A + x >= p * X && x <= p * X) return 1;
  else return 0;
}

void sol(void){
  long long l = 0, r = 1 << 30, m;
  if(!check(r)){
    cout << "-1" << endl;
    return;
  }
  while( l + 1 < r ){
    m = (l + r) >> 1;
    if(check(m)) r = m;
    else l = m;
  }
  cout << (q * r) - y << endl;
}

int main(void){
  int i, j;
  cin >> T;
  while(T--){
    ini();
    sol();
  }
}
