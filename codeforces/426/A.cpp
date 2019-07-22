#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[500];
char str[10];
void ini(void){
  arr[62] = 1;
  arr[118] = 2;
  arr[60] = 3;
  scanf("%s", str);
  M = arr[ str[0] ];
  scanf("%s", str);
  Q = arr[ str[0] ];
  scanf("%d", &N);
  N %= 4;
}

void sol(void){
  
  int x = M + N, y = M - N;
  if(x >= 4) x -= 4;
  if(y < 0) y += 4;
  if(x == Q && y == Q) printf("undefined\n");
  else if(x == Q) printf("cw\n");
  else if(y == Q) printf("ccw\n");
  else printf("undefined\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
