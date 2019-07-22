#include <cstdio>
#include <cstring>
using namespace std;
int T, N, M, Q;
typedef long long ll;

#define mod7 1000000007ll
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
ll mypow( ll _a , ll _x , ll _mod = mod7 ){
  if( _x == 0 || _a == 1 ) return 1ll;
  ll _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
inline ll _div( ll _x, ll _y, ll _mod = mod7 ){
  return mul( _x, mypow( _y, _mod - 2, _mod ) );
}
ll ans[1005], f[1005], finv[1005];
ll C(ll n, ll m) {
  return mul(f[n], mul(finv[m], finv[n-m]));
}

void ini(void){
  scanf("%d%d", &N, &M);
}

ll sol(void){
  if(M > N) return 0;
  for(int i = 1; i <= M; ++i){
    ans[i] = mypow(i, N);
    //printf("%lld ", ans[i]);
  }
  //printf("\n");
  //printf("after sub: ");
  for(int i = 1; i < M; ++i){
    for(int j = i + 1; j <= M; ++j){
      ans[j] = sub(ans[j], mul( ans[i], C(j, i) ));
    }
    //printf("%lld ", ans[i]);
  }
  //printf("\n");
  return ans[M];
}

int main(void){
  f[0] = finv[0] = 1;
  for(int i=1; i<1005; ++i) f[i] = mul(f[i-1], i);
  finv[1004] = mypow(f[1004], mod7-2);
  for(int i=1003; i>0; --i) finv[i] = mul(finv[i+1], i+1);
  freopen("galactic.in", "r", stdin);
  
  scanf("%d", &T);
  while(T--){
    ini();
    printf("%lld\n", sol());
  }
}
