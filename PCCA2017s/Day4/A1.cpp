#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int T, N, M, Q;
long long arr0[105];
pair<long long, int> arr1[105];
vector<int> v[105];
void ini(void){
  int x, y;
  scanf("%d %d", &N, &M);
  for(int i = 0; i < M; ++i){
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for(int i = 1; i <= N; ++i){
    arr0[i] = v[i].size();
  }
}

int find(void){
  for(int i = 1; i <= N; ++i){
    arr1[i] = make_pair(arr0[i], i);
  }
  /*
  for(int i = 1; i <= N; ++i){
    printf("%lld,%d ", arr1[i].first, arr1[i].second);
  }
  printf("=>");
  */
  sort(arr1, arr1 + N + 1);
  /*
  for(int i = 1; i <= N; ++i){
    printf("%lld,%d ", arr1[i].first, arr1[i].second);
  }
  printf("\n");
  */
  return arr1[1].second;
}

void sol(void){
  int ans = 0;
  vector<int> a;
  while( arr0[ (Q = find()) ] <= 100 ){
    ++ans;
    arr0[Q] = 500;
    a.push_back(Q);
    for(int i = 0; i < v[Q].size(); ++i){
      int x = v[Q][i];
      arr0[ x ] = 500;
      for(int j = 0; j < v[x].size(); ++j){
        if(arr0[ x ] <= 100) --arr0[ x ];
      }
    }
    /*
  printf("Q = %d =>", Q);
  for(int i = 1; i <= N; ++i){
    printf("%d ", arr0[i]);
  }
  printf("\n");
  */
  }
  printf("%d\n", ans);
  for(int i = 0; i < a.size(); ++i) printf("%d ", a[i]);
  printf("\n");
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
