#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;
vector<long long> v;
void ini(void){
  cin >> N >> M;
}

void sol(void){
  double A = sqrt(N);
  for(int i = 1; i <= A; ++i){
    if(N % i == 0){
      v.push_back(i);
      if(i != N / i) v.push_back(N / i);
    }
  }
  sort(v.begin(), v.end());
  if(v.size() < M) cout << "-1" << endl;
  else cout << v[M - 1] << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
