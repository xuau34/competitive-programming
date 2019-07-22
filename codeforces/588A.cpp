#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  cin >> N;
}

void sol(void){
  int a, p, mi = 101;
  long long sum = 0;

  while( N-- ){
    cin >> a >> p;
    if( p < mi ) mi = p;
    sum += a * mi;
  }

  cout << sum << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
