/*
  (抄)

  最大特點是將旋轉幾度設為四個狀態，而這四個狀態是會循環的。
  因此可以容易推出我下一個要走的人，他的狀態為多少時，是否可以走到。
  以及當我的狀態是多少時，我還是否能通過某一邊。
  全由 s 和 stat 來去決定，超厲害der~
 */

#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, way[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, X, Y;
bool v[1005][1005][4], s[1005][1005][4];
char str[1005][1005];

struct no{
  int x, y, dis, stat;
  no(int a, int b, int c, int d): x(a), y(b), dis(c), stat(d){}
};
queue< struct no > que;
void ini(void){
  int x, y;
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i) scanf("%s", str[i]);

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      if(str[i][j] == '+') s[i][j][0] = s[i][j][1] = s[i][j][2] = s[i][j][3] = 1;
      else if(str[i][j] == '-') s[i][j][1] = s[i][j][3] = 1;
      else if(str[i][j] == '|') s[i][j][0] = s[i][j][2] = 1;
      else if(str[i][j] == '^') s[i][j][0] = 1;
      else if(str[i][j] == '>') s[i][j][1] = 1;
      else if(str[i][j] == '<') s[i][j][3] = 1;
      else if(str[i][j] == 'v') s[i][j][2] = 1;
      else if(str[i][j] == 'L') s[i][j][0] = s[i][j][1] = s[i][j][2] = 1;
      else if(str[i][j] == 'R') s[i][j][0] = s[i][j][2] = s[i][j][3] = 1;
      else if(str[i][j] == 'U') s[i][j][1] = s[i][j][2] = s[i][j][3] = 1;
      else if(str[i][j] == 'D') s[i][j][0] = s[i][j][1] = s[i][j][3] = 1;
    }
  }

  scanf("%d%d", &x, &y), --x, --y;
  que.push( no(x, y, 0, 0) ), v[x][y][0] = 1;
  scanf("%d%d", &X, &Y), --X, --Y;
}

void sol(void){
  int x, y, di, st, xx, yy;
  while(!que.empty()){
    x = que.front().x, y = que.front().y, di = que.front().dis, st = que.front().stat;
    que.pop();
    if(x == X && y == Y){
      printf("%d\n", di);
      return;
    }
    if(!v[x][y][(st + 1) % 4]){
      v[x][y][(st + 1) % 4] = 1;
      que.push( no(x, y, di + 1, (st + 1) % 4) );
    }
    for(int i = 0; i < 4; ++i){
      if(s[x][y][(i - st + 4) % 4]){
        xx = x + way[i][0], yy = y + way[i][1];
        if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
        if(s[xx][yy][(i - st + 6) % 4] && !v[xx][yy][st]){
          v[xx][yy][st] = 1;
          que.push( no(xx, yy, di + 1, st) );
        }
      }
    }
  }
  printf("-1\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
