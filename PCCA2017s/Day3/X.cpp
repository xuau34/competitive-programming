#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[1005];
void ini(void){
  scanf("%s", str);
  N = strlen(str);
}

void sol(void){
  for(int i = 1; i < N; ++i){
    double c, j;
    if(str[i] == str[i - 1]){
      j = 0.5;
      c = i - 0.5;
    }else{
      j = 0;
      c = i;
    }
    for(; (long long)(c - j - 1) >= 0 && c + j + 1 < N && str[(int)(c - j - 1)] == str[(int)(c + j + 1)]; ++j) ;
    if( str[(int)(c - j)] == str[(int)(c + j)] ) M = max(M, (int)(j * 2) + 1 );
    cout << j << " " << M << endl;
  }
  Q = N - M;
  if(Q & 1) cout << "Second" << endl;
  else cout << "First" << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
