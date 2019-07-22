#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void ini( void ){

}

int main(void){
  ios::sync_with_stdio(false);
  ll N, a = 0, b = 0, c, d, ans = 1;
  cin >> N;
  while( N-- ){
    cin >> c >> d;
    if( a == c && b == d ) continue;
    ll e = min( c, d ) - max( a, b );
    if( e >= 0 ) ans += e + (a != b);
    a = c, b = d;
  }
  cout << ans << endl;
}
