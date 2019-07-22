#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
map<string, int> m;
void ini(void){
  cin >> N;
}

void sol(void){
  string str;
  for(int i = 0; i < N; ++i){
    cin >> str;
    if(m[str] == 0){ 
      cout << "OK\n";
      m[str] = 1;
    }else{
      cout << str << m[str] << "\n";
      ++m[str];
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
