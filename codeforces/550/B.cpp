#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
int odd[ 2005 ], even[ 2005 ], lo, le;
void ini(void){
  cin >> N;
  lo = le = 0;
  for(int i = 0, x; i < N; ++i ){
    cin >> x;
    if( x & 1 ) odd[lo++] = x;
    else even[le++] = x;
  }
  sort( odd, odd+lo );
  sort( even, even+le );
}

long long sol( bool start ){
  int o = lo, e = le;
  for( int move = start; move - start < N; ++move ){
    if( move & 1 ){
      if( o == 0 ) break;
      --o;
    }else{
      if( e == 0 ) break;
      --e;
    }
  }
  long long sum = 0;
  while( o ) sum += odd[ --o ];
  while( e ) sum += even[ --e ];
  return sum;
}

int main(void){
  int i, j;

  ini();

  cout << min( sol(0), sol(1) ) << endl;

}
