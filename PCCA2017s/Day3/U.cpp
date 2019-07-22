#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[1005];

void ini(void){
  cin >> N;
  while(N--){
    cin >> M;
    if(!arr[M]){
      ++Q;
      arr[M] = 1;
      T = max(T, 1);
    }else{
      T = max(++arr[M], T);
    }
  }
}

void sol(void){
  cout << T << " " << Q << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
