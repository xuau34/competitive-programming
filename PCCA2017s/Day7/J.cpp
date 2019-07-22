#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, X, Y, ans, way[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool arr[15][15], visit[15][15];
void ini(void){
  char str[15];
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i){
    scanf("%s", str);
    for(int j = 0; j < M; ++j){
      if( str[j] == '*' ) arr[i][j] = 1;
      else if( str[j] == '.' ) arr[i][j] = 0;
      else{
        switch (str[j]){
          case 'U': 
            Q = 0;
            break;
          case 'R':
            Q = 1;
            break;
          case 'D':
            Q = 2;
            break;
          case 'L':
            Q = 3;
            break;
        }
        X = i, Y = j;
      }
    }
  }
  ans = 1;
  visit[X][Y] = 1;
}

void sol(void){
  int haha = 9999;
  //printf("(%d, %d) Q = %d haha = %d\n", X, Y, Q, haha);
  while(haha){
    if( X + way[Q][0] < 0 || X + way[Q][0] >= N || Y + way[Q][1] < 0 || Y + way[Q][1] >= M || arr[ X + way[Q][0] ][ Y + way[Q][1] ]){
      Q = (Q == 3)? 0: Q + 1;
      --haha;
    }else{
      X += way[Q][0];
      Y += way[Q][1];
      if(!visit[ X ][ Y ]) ++ans, haha = 10000, visit[ X ][ Y ] = 1;
      else --haha;
    }
    //printf("(%d, %d) Q = %d haha = %d\n", X, Y, Q, haha);
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
