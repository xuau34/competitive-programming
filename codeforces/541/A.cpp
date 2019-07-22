#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void ini( void ){

}

int main(void){
  ios::sync_with_stdio(false);
  
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << a + 2 * b + c + 2 * d + 4 + abs( a - c ) << endl;
}
