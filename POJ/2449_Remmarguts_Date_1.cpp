/*
  Kth Shortest Path
  By A* (Dijkstra)

  A*: F = G + H
  F 為一個評估值，同Dijkstra que的距離一樣。
  G: S -> x
  H: 可以有很多種形式，在此為 x -> T 的最短距。 （由Dijkstra + 反向邊）

  A*的走訪同Dijkstra。
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int S, T, K, N, M, arr[1005];
vector< pair<int, int> > no[1005], nor[1005];
bool v[1005];
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; ++i){
    scanf("%d%d%d", &S, &T, &K);
    no[S].push_back( make_pair(T, K) );
    nor[T].push_back( make_pair(S, K) );
  }
  scanf("%d%d%d", &S, &T, &K);
  if(S == T) ++K;
}

int Dij(void){  //反向，建立各點到T的最短路(nor)
  memset(arr, 127, sizeof(arr)); arr[T] = 0;
  int x;
  priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > que;
  que.push( make_pair(0, T) ); v[T] = 1;
  while(!que.empty()){
    x = que.top().second; que.pop();
    v[x] = 1; //錯在這裡rrrrr
    for(int i = 0, j = nor[ x ].size(); i < j; ++i){
      if(!v[ nor[x][i].first ] && arr[x] + nor[x][i].second < arr[ nor[x][i].first ]){
        arr[ nor[x][i].first ] = arr[x] + nor[x][i].second;
        //v[ nor[x][i].first ] = 1;
        que.push( make_pair(arr[ nor[x][i].first ], nor[x][i].first) );
      }
    }
  }
  return arr[S] == arr[1004];
}

int sol(void){
  //if(Dij()) return -1;
  //for(int i = 1; i <= N; ++i) printf("arr[%d] = %d\n", i, arr[i]);

  //   A*
  int x, y;
  priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > que;
  que.push( make_pair(0, S) );
  while(!que.empty()){
    //printf("(%d, %d) => ", que.top().first,  que.top().second);
    x = que.top().second; y = que.top().first; que.pop();
    if(x == T && !(--K)) return y;
    //printf("K = %d\n", K);
    for(int i = 0, j = no[ x ].size(); i < j; ++i)
      que.push( make_pair(y + no[x][i].second, no[x][i].first) );
  }
  return -1;

}

int main(void){
  int i, j;

  ini();

  printf("%d\n", sol() );

}
