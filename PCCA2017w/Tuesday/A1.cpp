#include <bits/stdc++.h>
using namespace std;
struct edge{ int to, cap, rev; };

vector<edge> G[10205];
int level[10205];
int iter[10205];

int arr[10205][2], n;

void add_edge(int from, int to, int cap){
  //cout<<from<<","<<to<<","<<cap<<endl;
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){from, 0, G[from].size() - 1});
}

void bfs(int s){
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[s] = 0;
  que.push(s);
  while(!que.empty()){
    int v = que.front(); que.pop();
    for(int i = 0; i < G[v].size(); i++){
      edge &e = G[v][i];
      if(e.cap > 0 && level[e.to] < 0){
        level[e.to] = level[v] + 1;
        que.push(e.to);
      }
    }
  }
}

int dfs(int v, int t, int f){
  if(v == t) return f;
  for(int &i = iter[v]; i < G[v].size(); i++){
    edge &e = G[v][i];
    if(e.cap > 0 && level[v] < level[e.to]){
      //cout<<v<<"->"<<e.to<<" ";
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t){
  int flow = 0, f;
  for(;;){
    bfs(s);
    if(level[t] < 0) return flow;
    memset(iter, 0, sizeof(iter));
    do{
      f = dfs(s, t, 1<<30);
      flow += f;
    }while(f > 0);
  }
}

void build(int m){
  memset(G, 0, sizeof(G));
  int i, j;
  for(i = 1; i <= n; i++) add_edge(i + 10000, 10204, m);
  for(i = 0; i <= 10000; i++) add_edge(10203, i, 1);
  for(i = 1; i <= n; i++){
    for(j = arr[i][0]; j < arr[i][1]; j++){
      add_edge(j, i + 10000, 1);
    }
  }
}

int Dinic(int m){
  build(m);
  return max_flow(10203, 10204);
}

int main(void){
  int i, j, l, r;
  scanf("%d", &n);
  for(i = 1, l = 0 , r = (10000/n) + 1; i <= n; i++) scanf("%d %d", arr[i], arr[i] + 1);
  //i = Dinic(2);
    //cout<<endl<<'2'<<"="<<i<<" ";
  //while(1);
  while(l + 1 < r){
    j = (l + r)/2;
    i = Dinic(j);
    if(i == j * n) l = j;
    else r = j;
  }
  cout<<l*n<<endl;
}
