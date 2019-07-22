#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, bt[100005];
long long arr[100005];
bool v[100005];
vector< pair<int, int> > nor[100005];
const long long INF = 1e13;
void ini(void){
  int x, y, z;
  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; ++i){
    scanf("%d%d%d", &x, &y, &z);
    nor[x].push_back( make_pair(y, z) );
    nor[y].push_back( make_pair(x, z) );
  }
  //printf("INF = %lld\n", INF);
}

bool Dij(void){  //反向，建立各點到T的最短路(nor)
  //memset(arr, 127, sizeof(arr)); arr[T] = 0;
  for(int i = 2; i <= N; ++i) arr[i] = INF; 
  int x;
  priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > que;
  que.push( make_pair(0, 1) ); v[1] = 1;
  while(!que.empty()){
    x = que.top().second; que.pop();
    v[x] = 1; //錯在這裡rrrrr
    for(int i = 0, j = nor[ x ].size(); i < j; ++i){
      if(!v[ nor[x][i].first ] && arr[x] + nor[x][i].second < arr[ nor[x][i].first ]){
        arr[ nor[x][i].first ] = arr[x] + nor[x][i].second;
        bt[ nor[x][i].first ] = x;
        //v[ nor[x][i].first ] = 1;
        que.push( make_pair(arr[ nor[x][i].first ], nor[x][i].first) );
      }
    }
  }
  return arr[N] == INF;
}
void sol(void){
  if(Dij()) printf("-1\n");
  else{
    vector<int> ans;
    int x = N;
    while(x){
      ans.push_back(x);
      x = bt[x];
    }
    for(int i = ans.size() - 1; i >= 0; --i) printf("%d ", ans[i]);
    printf("\n");
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
