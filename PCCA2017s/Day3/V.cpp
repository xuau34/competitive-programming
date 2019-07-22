#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[300][300];

void ini(void){
  cin >> N;
}

void sol(void){
  Q = 0;
  for(int i = 0; i < N; i += 2){
    for(int j = 0; j < N; ++j){
      arr[j][i] = ++Q;
    }
    for(int j = N - 1; j >= 0; --j){
      arr[j][i + 1] = ++Q;
    }
  }
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j) cout << arr[i][j] << " ";
    cout << endl;
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
