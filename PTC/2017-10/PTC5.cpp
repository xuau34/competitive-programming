#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int T, N, M, Q;

struct Line{
  int x, y, len;
  bool operator < (Line &Y){
    return (x == Y.x)? y < Y.y: x < Y.x;
  }
};

void sol(void){
  pair<int, int> arr[1005];
  Line ln[1005], left;
  scanf("%d", &N);
  for(int i = left.len = 0; i < N; ++i) scanf("%d%d", &arr[i].first, &arr[i].second);
  sort(arr, arr + N);
  for(int i = M = 0; i < N; i += 2, ++M){
    ln[M].x = arr[i].first;
    ln[M].y = arr[i + 1].second;
    ln[M].len = arr[i + 1].second - arr[i].second;
  }
  for(int i = 0; i < M; ++i){
    printf("(%d, %d, %d) ", ln[i].x, ln[i].y, ln[i].len);
  }
  printf("\n");
  for(int i = 0; i < M; ++i){
    if(left.len == 0) left = ln[i];
    else if()

  }
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    sol();
  }
}
