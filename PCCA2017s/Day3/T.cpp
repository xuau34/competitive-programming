#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;

void ini(void){
  cin >> T;
}

void fail(void){
  cout << "NO" << endl;
  exit(0);
}

void sol(void){
  while(T){
    N = T % 10;
    if(N == 4){
      if(!M) M = 1;
      else if(M == 1) M = 2;
      else fail();
    }else if(N == 1){
      M = 0;
    }else fail();

    T /= 10;
  }
  if(!M) cout << "YES" << endl;
  else fail();
}

int main(void){
  int i, j;

  ini();

  sol();

}
