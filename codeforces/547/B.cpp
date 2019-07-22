#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  cin >> N;
}

void sol(void){
  int ans = 0, count = 0;
  bool x[N];
  for(int i = 0; i < N; ++i) cin >> x[i];
  for(int i = 0; i < N; ++i){
    if(x[i]) ++count;
    else{
      if( count > ans ) ans = count;
      count = 0;
    }
  }
  for(int i = 0; i < N && x[i]; ++i, ++count);
  cout << max( count, ans ) << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
