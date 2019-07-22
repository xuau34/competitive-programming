#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  cin >> T;
}

void sol(void){
  for(int Case = 1; Case <= T; ++ Case){
    cin >> N;
    int A = 0, B = 0, ten = 1, x;
    while(N){
      x = N % 10;
      if(x == 4){
        A += ten << 1;
        B += ten << 1;
      }else A += x * ten;
      N = N / 10;
      ten = ten * 10;
    }
    cout << "Case #" << Case << ": " << A << " " << B << endl;
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
