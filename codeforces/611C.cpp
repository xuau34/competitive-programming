/*
  其實可以二維prefix sum
  集中在右下角的話，
  那樣只要取 [X][Y] - [X][y - 1] - [x - 1][Y] + [x - 1][y - 1] 就可以惹 OAO"
*/
#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, up[505][505], lef[505][505];
char str[505][505];
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i) scanf("%s", str[i]);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      if(str[i][j] == '.'){
        if(j > 0 && str[i][j - 1] == '.') ++lef[i][j];
        if(i > 0 && str[i - 1][j] == '.') ++up[i][j];
      }
      if(j > 0) lef[i][j] += lef[i][j - 1], up[i][j] += up[i][j - 1];
    }
  }
  /*
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j) printf("(%d,%d) ", lef[i][j], up[i][j]);
    printf("\n");
  }
  */
}

void sol(void){
  scanf("%d", &Q);
  while(Q--){
    int ans = 0, x, y, X, Y;
    scanf("%d%d%d%d", &x, &y, &X, &Y);
    for(int i = x - 1; i < X; ++i) ans += lef[i][Y - 1] - lef[i][y - 1]; 
    //printf("%d ", ans);
    for(int i = x; i < X; ++i) ans += up[i][Y - 1] - ((y > 1)? up[i][y - 2]: 0);
    printf("%d\n", ans);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
