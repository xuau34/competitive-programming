#include <bits/stdc++.h>

using namespace std;

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
inline bool equal( double _x ,  double _y ){
  return _x > _y - eps && _x < _y + eps;
}
