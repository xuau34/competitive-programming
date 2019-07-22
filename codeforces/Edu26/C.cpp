#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
struct str{
  int x, y;
} arr[105];
void ini(void){
  scanf("%d%d%d", &T, &N, &M);
  if(N > M) swap(N, M);
  for(int i = 0; i < T; ++i){
    scanf("%d%d", &arr[i].x, &arr[i].y);
    if(arr[i].x > arr[i].y) swap(arr[i].x, arr[i].y);
  }
}

inline bool check(int x, int y){
  int ax, ay, bx, by;
  ax = N - arr[x].x, ay = M; if(ax > ay) swap(ax, ay);
  bx = N, by = M - arr[x].y; if(bx > by) swap(bx, by);
  if(ax >= 0 && bx >= 0 && ( (arr[y].x <= ax && arr[y].y <= ay) || (arr[y].x <= bx && arr[y].y <= by) ))
      return 1;
  ax = N - arr[x].y, ay = M; if(ax > ay) swap(ax, ay);
  bx = N, by = M - arr[x].x; if(bx > by) swap(bx, by);
  return ax >= 0 && bx >= 0 && ( (arr[y].x <= ax && arr[y].y <= ay) || (arr[y].x <= bx && arr[y].y <= by) );
}

void sol(void){
  for(int i = 0; i < T; ++i){
    for(int j = i + 1; j < T; ++j){
      if(check(i, j)) Q = max(Q, arr[i].x * arr[i].y + arr[j].x * arr[j].y);
    }
  }
  printf("%d\n", Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
