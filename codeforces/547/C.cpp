#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, q[200005];

void ini(void){
  cin >> N;
  for( int i = 1; i < N; ++i ) cin >> q[i];
}

void sol(void){
  int p[N + 1];
  p[0] = p[1] = 0;
  for(int i = 1; i < N; ++i ){
    p[i + 1] = p[i] + q[i];
    if(p[i + 1] < p[0]) p[0] = p[i + 1];
  }
  --p[0];
  for(int i = 1; i <= N; ++i) p[i] -= p[0];

  bool check[N + 1];
  memset(check, 0, sizeof(check));
  for(int i = 1; i <= N; ++i){
    if( p[i] < 1 || p[i] > N || check[ p[i] ] ){
      cout << -1 << endl;
      return;
    }
    check[ p[i] ] = 1;
  }
  for(int i = 1; i <= N; ++i ) cout << p[i] << " \n"[i == N];
}

int main(void){
  int i, j;

  ini();

  sol();

}
