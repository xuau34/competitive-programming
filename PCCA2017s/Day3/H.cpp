#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
string str;
void ini(void){
  cin >> N;
}

void sol(void){
  while(N--){
    cin >> str >> M >> Q;
    if(M >= 2400 && M < Q) T = 1;
  }
  if(T) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
