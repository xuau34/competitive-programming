#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
void ini(void){
  cin >> T >> N >> M;
}

bool check(int X){
  int i = (X / 50) % 475;
  for(int j = 0; j < 25; j++){
    i = (i * 96 + 42) % 475;
    //cout << i + 26 << endl;
    if(i + 26 == T) return true;
  }
  return false;
}

void sol(void){
  int x = N, ans = 0;
  while(x >= M){
    if(check(x)){
      cout << "0" << endl;
      return;
    }
    x -= 50;
  }
  x = N;
  while(x < M){
    x += 100;
    ans += 2;
  }
  while(!check(x)){
    x += 50;
    ++ans;
  }
  cout << (ans + 1) / 2 << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
