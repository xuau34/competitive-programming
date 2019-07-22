/*
  重要的是每層要多加的數為 上一層 - C_(i, N) * 2   (i 為上一層之index )
  不懂為什麼是C_(i ,N)就是了
  另外要注意的是C_放進去會是N^2，所以須將之優化。
 */

#include <bits/stdc++.h>
using namespace std;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
inline ll _div( ll _x, ll _y, ll _mod = mod7 ){
  return mul( _x, mypow( _y, mod7 - 2, mod7 ) );
}
long long C_(int A, int B){
  long long ret = 1;
  for(int i = (A - B) + 1; i <= A; ++i) ret = mul(ret, i);
  //printf("C_(%d, %d) = %lld => ", A, B, ret);
  for(int i = 2; i <= B; ++i) ret = _div(ret, i);
  //printf("%lld\n", ret);
  return ret;
}

int T, N, M, Q;
long long Ad = 1, sum = 1, C = 1, D = 0;
void ini(void){
  scanf("%d", &N);
}

void sol(void){
  for(int i = 0, j = N << 1; i < j; ++i){
    if(i < N) sum = add( sum, (Ad = add(Ad, Ad)) );
    else{
      if(!D){
        sum = add(sum, (Ad = ( mul(sub( Ad, 1 ), 2 ) )) );
      }else{
        sum = add(sum, (Ad = ( mul(sub( Ad, ( C = _div( mul(i, C), D ) ) ), 2 ) )) );
      }
      ++D;
    }
  //printf("%lld %lld %d\n", sum, Ad, i);
  }
  printf("%lld\n", sum);
}

int main(void){
  int i, j;

  ini();

  sol();

}
