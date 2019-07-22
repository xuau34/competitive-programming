#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;

void ini(void){
  cin >> T >> N;
}

void sol(void){
  long long ans = -2000000000;
  while(T--){
    cin >> M >> Q;
    ans = max(ans, M - ( (Q > N)? Q - N: 0 ));
  }
  cout << ans << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
