#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int T, N, M, Q;
int arr[105][105];
bool v[105];
void ini(void){
  int i, j;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++) scanf("%d", arr[i] + j);
  }
  return;
}

int main(void){
  int i, j;
  while(scanf("%d", &N) == 1){
    int ans = 0;
    memset(v, 0, sizeof(v));
    ini();
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    pair<int, int> p;
    q.push(make_pair(0, 0));
    while(!q.empty()){
      if(v[q.top().second]){
        q.pop();
        continue;
      }
      /*
      while(!q.empty() && v[q.top().second]){
        q.pop();
        cout<<q.size()<<endl;
      }
      */
      p = q.top();
      q.pop();
      v[p.second] = 1;
      ans += p.first;
      for(i = 0; i < N; i++){
        if(arr[p.second][i] && !v[i]) q.push(make_pair(arr[p.second][i], i));
      }
    }
    printf("%d\n", ans);
  }
}
