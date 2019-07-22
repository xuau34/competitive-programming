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

typedef long long ll;

ll _mod = 9901;
inline ll add( ll _x , ll _y ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline ll sub( ll _x , ll _y ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline ll mul( ll _x , ll _y ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}

ll A,B;
vector<pair<int,int> > prim;

void get_prim(){
  for(int i=2, cnt;i*i<=A;++i)if(A%i==0){
    cnt = 0;
    while(A%i==0) A/=i, ++cnt;
    prim.push_back({i, cnt*B});
    cout << cnt*B << endl;
  }
  if(A > 1) prim.push_back({A, B});
}

void sol(){
  get_prim();
  ll ans = 1, tmp;
  for(int i=0;i<(int)prim.size();++i){
    tmp = 0;
    for(int j=0;j<=prim[i].second;++j){
      tmp = mul(tmp, prim[i].first);
      tmp = add(tmp, 1);
    }
    printf("(%d, %d): tmp = %lld\n", prim[i].first, prim[i].second, tmp);
    ans = mul(ans, tmp);
  }
  cout << ans << endl;
}

int main(){
  cin >> A >> B;
  sol();
}
