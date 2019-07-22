#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
map<char, char> m;
void ini(void){
  string A, B, C;
  cin >> A >> B >> C;
  N = A.length();
  M = C.length();
  for(int i = 0; i < N; ++i){
    m[A[i]] = B[i];
  }
  char c;
  for(int i = 0; i < M; ++i){
    if(m.find( tolower( C[i] ) ) != m.end()) c = m[ tolower( C[i] ) ];
    else c = C[i];
    if(islower( C[i] ) ) printf("%c", tolower(c) );
    else printf("%c", toupper(c) );
  }
  printf("\n");
}

void sol(void){

}

int main(void){
  int i, j;

  ini();

  sol();

}
