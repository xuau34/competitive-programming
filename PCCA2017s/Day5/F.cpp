#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

#define mod7 9901ll
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

int T, N, M, Q, arr[1005];
vector< pair<int, long long> > vpii;
void ini(void){
  int x = N ,j;
  for(int i = 2, n = sqrt((double)N); i <= n && x > 1; ++i){
    for(j = 0; x % i == 0; ++j) x /= i;
    if(j) vpii.push_back( make_pair(i, j * M) );
  }
  if(x > 1) vpii.push_back( make_pair(x, M) );
}
void sol(void){
  if(N == 0){
    printf("0\n");
    return;
  }
  long long sum, ans = 1;
  for(int i = 0, s = vpii.size(); i < s; ++i ){
    sum = 1;
    for(long long j = vpii[i].second, x = vpii[i].first, y = 1; j ; j >>= 1, y = mul( y, add( x, 1 )), x = mul(x, x)){
      if(j & 1) sum = add( mul(sum, x), y );
    }
    ans = mul(ans, sum);
  }
  printf("%lld\n", ans);
}

int main(void){
  int i, j;

  while( scanf("%d %d", &N, &M) == 2 ) {
    ini();
    sol();
    vpii.clear();
  }
}
