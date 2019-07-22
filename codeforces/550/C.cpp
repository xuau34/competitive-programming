#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[200005];

void ini(void){
  cin >> N;
  for( int i = 0; i < N; ++i ) cin >> arr[i];
  sort( arr, arr + N );
}

void sol(void){
  int in[200005], de[200005], li = 0, ld = 0;
  for( int i = 0, l; i < N; ++i ){
    for( l = i + 1; l < N && arr[l] == arr[l - 1]; ++l );
    l -= i;
    if( l > 2 ){
      cout << "NO" << endl;
      return;
    }
    in[ li++ ] = arr[i];
    if( l > 1 ) de[ ld++ ] = arr[i];
    i += l - 1;
  }
  cout << "YES" << endl << li << endl;
  for( int i = 0; i < li; ++i ) cout << in[i] << " ";
  cout << endl << ld << endl;
  for( int i = ld - 1; i >= 0; --i ) cout << de[i] << " ";
  cout << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
