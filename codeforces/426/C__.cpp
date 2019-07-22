#include <bits/stdc++.h>
#define abs(x) ((x)<0 ? (-(x)) : (x) )

typedef long long ll;
typedef pair<ll,ll> pll;

inline ll randll(){
  return  ( (ll)rand() << 30 ) + ( rand() << 15 ) + rand();
} 
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool witness(ll a,ll n,ll u,int t){
  ll x = mypow(a, u, n);
  for(int i=0 ; i<t ; i++) {
    ll nx = mymul(x, x, n);
    if(nx==1 && x!=1 && x!=n-1) return 1;
    x=nx;
  }
  return x!=1;
}
bool miller_rabin(ll n,int s=30) {
  if(n<2) return 0;
  if(~n&1) return n == 2;
  ll u=n-1; int t=0;
  while(~u&1) u>>=1, t++;
  while(s--){
    ll a=randll()%(n-1)+1;
    if(witness(a,n,u,t)) return 0;
  }
  return 1;
}

long long Pollard_rho(long long x, long long c){
  long long i = 1, k = 2, x0 = rand() % x, y = x0;
  //cout<<"x = "<<x<<", x0 = "<<x0<<", y = "<<y<<endl;
  while(1){
    ++i;
    x0 = (mult_mod(x0, x0, x) + c) %x;
    /*
    cout<<"x0 = "<<x0<<", y = "<<y<<endl;
    int xx;
    while(cin>>xx && xx);
    */
    long long d = __gcd((y - x0 + x) % x, x);
    if(d != 1 && d != x) return d;
    if(y == x0) return x;
    if(i == k){
      y = x0;
      k += k;
    }
  }
}

int T, N, M;
long long ans;

void findfac(long long n){
  if(Miller_Rabin(n)){
    ++ans;
    return;
  }
  long long p = n;
  while(p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
  //cout<<"p = "<<p<<", n / p = "<<n/p<<endl;
  findfac(p);
  findfac(n / p);
}

void ini(void){
  scanf("%d%d", &N, &M);
  ans = 0;
}

bool sol(void){
  findfac(N); findfac(M);
  if(ans % 3 == 0) return 1;
  else return 0;
}

int main(void){

  /*
  while(cin>>i){
    cout<<Miller_Rabin(i)<<endl;
  }
  */
  scanf("%d", &T);
  while(T--){
    ini();
    if( sol() ) printf("Yes\n");
    else printf("No\n");
  }


}
