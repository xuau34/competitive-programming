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

int T, N, M, Q, arr[1005];
//vector<int> pas;
void ini(void){
  scanf("%d", &N);
  scanf("%d", &Q);
  for(int i = 1; i < N; ++i){
    scanf("%d", &M);
    if(M > 1) arr[i] = M - 1;
  }
  //pas.push_back(1);
}
/*
void pasta( int n ){
  while( pas.size() < n ){
    int pre = 0, post;
    for(int i = 0; i < pas.size(); ++i){
      post = pas[i];
      //printf("pre = %d pas[%d] = %d => ", pre, i, pas[i]);
      pas[i] += pre;
      //printf("%d\n", pas[i]);
      pre = post;
    }
    pas.push_back(1);

    
    printf("pasta(%d): ", pas.size());
    for(int i: pas) printf("%d ", i);
    printf("\n");
    cin >> N;
    
  }
  printf("pasta(%d): ", n);
  for(int i: pas) printf("%d ", i);
  printf("\n");
}
*/

long long C_(int A, int B){
  long long ret = 1;
  for(int i = (A - B) + 1; i <= A; ++i) ret = mul(ret, i);
  //printf("C_(%d, %d) = %lld => ", A, B, ret);
  for(int i = 2; i <= B; ++i) ret = _div(ret, i);
  //printf("%lld\n", ret);
  return ret;
}

void sol(void){
  long long ans = 1, q;
  //++Q;
  for( int j = 1 ; j < N; ++j ){
    if( !arr[j] ) continue;
    T = arr[j], q = Q + j;
    //pasta( T );
    long long sum = 0;
    for(int i = 1; i <= q && i <= T; ++i){
      sum = add( sum , mul( C_( q, i ) , C_(T - 1, i - 1) ) );
      //printf("j = %d: sum += C(%lld, %d) * C(%d, %d)\n", j, q, i, T-1, i-1 );
    }
    ans = mul(ans , sum);
    Q += T;
    //printf("T = %d: sum = %lld, ans = %lld\n", T, sum, ans);
  } 
  printf("%lld\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
