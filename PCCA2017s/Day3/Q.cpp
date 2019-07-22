#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
string s, S;
void ini(void){
  cin >> s >> S;
}

void sol(void){
  T = s.size();
  for(int i = 0; i < T; ++i){
    if(s[i] != S[T - i - 1]){
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
