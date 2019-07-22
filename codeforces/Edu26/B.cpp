#include <bits/stdc++.h>
using namespace std;
int T[30], N, M, Q[30];
char str[105][105];
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i) scanf("%s", str[i]);
  char c = str[0][0];
  for(int i = Q[str[0][0] - 'A'] = 1; i < N; ++i) if(str[i][0] != c){
    c = str[i][0]; ++Q[str[i][0] - 'A'];
  }
  c = str[0][0];
  for(int i = T[str[0][0] - 'A'] = 1; i < M; ++i) if(str[0][i] != c){
    c = str[0][i]; ++T[str[0][i] - 'A'];
  }
}

bool sol(void){
  if(Q['R' - 'A'] == 1 && Q['G' - 'A'] == 1 && Q['B' - 'A'] == 1){
    int A, B, C;
    for(int i = 0; i < N; ++i){
      for(int j = 1; j < M; ++j) if(str[i][j] != str[i][0]) return 0;
    }
    for(A = 1; A < N && str[A - 1][0] == str[A][0]; ++A);
    for(B = A + 1; B < N && str[B - 1][0] == str[B][0]; ++B);
    for(C = B + 1; C < N && str[C - 1][0] == str[C][0]; ++C);
    //printf("Q: %d %d %d\n", A, B, C);
    return A == B - A && A == C - B;
  }else if(T['R' - 'A'] == 1 && T['G' - 'A'] == 1 && T['B' - 'A'] == 1){
    int A, B, C;
    for(int i = 0; i < M; ++i){
      for(int j = 1; j < N; ++j) if(str[j][i] != str[0][i]) return 0;
    }
    for(A = 1; A < M && str[0][A - 1] == str[0][A]; ++A);
    for(B = A + 1; B < M && str[0][B - 1] == str[0][B]; ++B);
    for(C = B + 1; C < M && str[0][C - 1] == str[0][C]; ++C);
    //printf("Q: %d %d %d\n", A, B, C);
    return A == B - A && A == C - B;
  }else return 0;
}

int main(void){
  int i, j;

  ini();

  if( sol() ) printf("YES\n");
  else printf("NO\n");

}
