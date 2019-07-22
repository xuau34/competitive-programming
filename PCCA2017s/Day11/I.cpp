#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, cnt[3], ans[505], edge[505];
bool arr[505][505], v[505];
void ini(void){
  scanf("%d%d", &N, &M);
  int x,y;
  for(int i = 0; i < M; ++i){
    scanf("%d%d", &x, &y);
    if(!arr[x][y]){
      ++edge[x], ++edge[y];
      arr[x][y] = arr[y][x] = 1;
    }
  }
}

void dfs(int x, int a){
  v[x] = 1;
  ++cnt[ (ans[x] = a) ];
  //printf("dfs(%d, %d) => cnt = %d\n", x, a, cnt[a]);
  for(int i = 1; i <= N; ++i) if(!v[i] && arr[x][i]) dfs(i, a);
  if(edge[x] != cnt[a] - 1){
    printf("No\n");
    exit(0);
  }
}

void sol(void){
  for(int i = 1; i <= N; ++i) if(edge[i] == N - 1) ans[i] = v[i] = 1;
  
  for(int i = 1; i <= N; ++i) if(v[i]){
    for(int j = 1; j <= N; ++j) if(arr[i][j]) --edge[j], arr[i][j] = arr[j][i] = 0;
    //printf("edge[%d] = %d\n", i, edge[i]);
  }
  /*
  for(int i = 1; i <= N; ++i){
    for(int j = 1; j <= N; ++j) printf("%d ", arr[i][j]);
    printf("\n");
  }
  printf("edge: ");
  for(int i = 1; i <= N; ++i) printf("%d ", edge[i]);
  printf("\n");
  */
  for(int i = 1; i <= N; ++i) if(!v[i]){
    dfs(i, 0); break;
  }
  //printf("%d, %d, %d\n", cnt[0], cnt[1], cnt[2]);
  for(int i = 1; i <= N; ++i) if(!v[i]){
    dfs(i, 2); break;
  }
  for(int i = 1; i <= N; ++i) if(!v[i]){
    printf("No\n");
    exit(0);
  }
  printf("Yes\n");
  for(int i = 1; i <= N; ++i) printf("%c", ans[i] + 'a');
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
