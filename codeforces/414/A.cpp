#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  cin >> N >> M >> Q;
}

void sol(void){
  int n, a, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin>>a;
    if( a > M && a < Q ) ++ans;
  }
  cout<<ans<<endl;
}

int main(void){
  int i, j;
  //cin >> T;
  T = 1;
  while(T--){
    ini();
    sol();
  }
}
