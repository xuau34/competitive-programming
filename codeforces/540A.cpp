#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char s[1005], S[1005];
void ini(void){
  scanf("%d%s%s", &N, s, S);
}

void sol(void){
  for(int i = 0; i < N; ++i){
    Q = abs(s[i] - S[i]);
    M += min(Q, 10 - Q);
  }
  printf("%d\n", M);
}

int main(void){
  int i, j;

  ini();

  sol();

}
