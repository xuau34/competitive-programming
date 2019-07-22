#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[200005];

void fill( int i );

void ini(void){
  cin >> N;
  for( int i = 0; i < N; ++i ) cin >> arr[i];
}

void sol(void){
  int test[200005];
  memcpy( test, arr, sizeof(arr) );
  sort( test, test + N );
  int most = test[0], times = 0;
  for(int i = 0, l; i < N; ++i){
    for( l = i + 1; l < N && test[l] == test[l - 1]; ++l );
    l -= i;
    if( l > times ){
      times = l;
      most = test[i];
    }
    i += l - 1;
  }

  cout << N - times << endl;
  for(int i = 0; i < N; ++i){
    if(arr[i] == most) fill( i );
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}

void fill( int i ){
  if( i + 1 < N && arr[i + 1] != arr[i]){
    cout << ((arr[i + 1] > arr[i])? 2: 1) << " " << i + 2 << " " << i + 1 << endl;
    arr[ i + 1 ] = arr[i];
    fill( i + 1 );
  }
  if( i - 1 >= 0 && arr[i - 1] != arr[i] ){
    cout << ((arr[i - 1] > arr[i])? 2: 1) << " " << i << " " << i + 1 << endl;
    arr[ i - 1 ] = arr[i];
    fill( i - 1 );
  }
}
