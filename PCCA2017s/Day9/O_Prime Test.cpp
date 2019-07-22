// n < 4,759,123,141        3 :  2, 7, 61
// n < 1,122,004,669,633    4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383          6 :  pirmes <= 13
// n < 2^64                       7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// Make sure testing integer is in range [2, n−2] if
// you want to use magic.

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <string>
#include <climits>
#include <numeric>
#include <iomanip>
using namespace std;

#define mod7 1000000007ll
typedef long long ll;
typedef ll LL;

ll gcd ( ll a, ll b )
{
  ll c;
  while ( a != 0 ) {
    c = a; a = b%a;  b = c;
  }
  return b;
}
#define abs(x) ((x)<0 ? (-(x)) : (x))

inline ll randll()
{
    return  ( (ll)rand() << 30 ) + ( rand() << 15 ) + rand();
} 
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
bool witness(LL a,LL n,LL u,int t){
	LL x=mypow(a,u,n);
	for(int i=0;i<t;i++) {
		LL nx=mul(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}
bool miller_rabin(LL n,int s=5000) {
	// iterate s times of witness on n
	// return 1 if prime, 0 otherwise
	if(n<2) return 0;
	if(!(n&1)) return n == 2;
	LL u=n-1; int t=0;
	// n-1 = u*2^t
	while(!(u&1)) u>>=1, t++;
	while(s--){
		LL a=randll()%(n-1)+1;
		if(witness(a,n,u,t)) return 0;
	}
	return 1;
}
LL f(LL x, LL mod){
	return add(mul(x,x,mod),1,mod);
}
LL pollard_rho(LL n) {
	if(!(n&1)) return 2;
  while(true){
    LL y=2, x=rand()%(n-1)+1, res=1;
    for(int sz=2; res==1; sz*=2) {
      for(int i=0; i<sz && res<=1; i++) {
        x = f(x, n);
        res = gcd(abs(x-y), n);
      }
      y = x;
    }
    if (res!=0 && res!=n) return res;
  }
}
int main(){
  int N;
  srand(time(0));
  ll in;
  scanf("%d", &N);
  for(int i=0;i<N;++i){
    scanf("%lld", &in);
      if(miller_rabin(in))
        puts("Prime");
      else 
        cout << pollard_rho(in) << endl;

  }
}
