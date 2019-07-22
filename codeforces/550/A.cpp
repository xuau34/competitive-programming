#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  cin >> T;
}
bool check[300];
void sol(void){
  string str;
  cin >> str;
  memset( check, 0, sizeof( check ) );
  for( int i = 0, l = str.length(); i < l; ++i ){
    if( check[ str[i] ] ){
      cout << "No" << endl;
      return;
    }
    check[ str[i] ] = 1;
  }
  int x = 0;
  while( x < 300 && !check[x] ) ++x;
  for( ; x + 1 < 300; ++x ){
    if( check[x + 1] && !check[x] ){
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main(void){
  int i, j;

  ini();

  while( T-- ){
    sol();
  }

}
