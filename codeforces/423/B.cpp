#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, L, minX = 200, minY = 200, maxX = 0, maxY = 0;
bool arr[105][105];
void ini(void){
  scanf("%d%d", &N, &M);
  char str[105];
  for(int i = 0; i < N; ++i){
    scanf("%s", str);
    for(int j = 0; j < M; ++j)
      if(str[j] == 'B'){
        arr[i][j] = 1;
        minX = min(minX, i), minY = min(minY, j);
        maxX = max(maxX, i), maxY = max(maxY, j);
      }
    //printf("X = (%d, %d), Y = (%d, %d)\n", X.first, X.second, Y.first, Y.second);
  }
}

void sol(void){
  int ans = 0, sum = 0;
  L = max(maxX - minX, maxY - minY) + 1;
  //printf("L = %d\n", L);
  if(L < 0) printf("1\n");
  else if(L > M || L > N) printf("-1\n");
  else{
    for(int i = minX; i <= maxX; ++i){
      for(int j = minY; j <= maxY; ++j){
        if(!arr[i][j]) ++ans;
        ++sum;
      }
    }
    printf("%d\n", ans + (L * L) - sum);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
