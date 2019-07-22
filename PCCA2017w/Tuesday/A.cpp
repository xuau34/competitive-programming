#include <bits/stdc++.h>
using namespace std;
struct edge{int to, cap, rev; };
vector<edge> tim[20005];
bool v[20005];
int n, arr[10005][2];
void add_vertex(int from, int to, int cap){
  if(cap == 2) cout<<"b = 2"<<endl;
  //cout<<from<<","<<to<<","<<cap<<endl;
  tim[from].push_back((edge){to, cap, tim[to].size()});
  tim[to].push_back((edge){from, 0, tim[from].size() - 1});
}
int dfs(int x, int t, int f){
  if(x == t) return f;
  v[x] = true;
  for(int i = 0; i < tim[x].size(); i++){
    if(!v[tim[x][i].to] && tim[x][i].cap > 0){
      //cout<<x<<" -> "<<tim[x][i].to<<" ";
      int g = dfs(tim[x][i].to, t, min(f, tim[x][i].cap));
        //cout<<x<<"=>"<<tim[x][i].to<<","<<tim[x][i].cap<<":"<<f<<endl;
        //cout<<x<<","<<tim[x][i].cap<<","<<g<<" ";
      if(g > 0){
        tim[x][i].cap -= g;
        tim[tim[x][i].to][tim[x][i].rev].cap += g;
        return g;
      }
    }
  }
  return 0;
}
void build(int b){
  int i, j;
  for(i = 1; i <= n; i++) add_vertex(i + 10000, 20004, b);
  for(i = 0; i <= 10; i++) add_vertex(20003, i, 1); //here~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  for(i = 1; i <= n; i++){
    for(j = arr[i][0]; j < arr[i][1]; j++){
      add_vertex(j, i + 10000, 1);
    }
  }
}
int main(void){
  int i, j, a, b, f;
  scanf("%d", &n);
  for(i = 1; i <= n; i++) scanf("%d %d", arr[i], arr[i] + 1);
  for(a = 0, b = (10000 / n) + 1; a + 1 < b; ){
    j = (a + b) / 2;
    //cout<<endl<<j<<endl;
    //cin>>j;
    memset(tim, 0, sizeof(tim));
    build(j);
    f = 0;
    memset(v, 0, sizeof(v));
    cout<<"f: ";
    while((i = dfs(20003, 20004, 1<<30))){
      f += i;
      cout<<i<<","<<f<<" ";
      i = dfs(20003, 20004, 1<<30);
    }
    cout<<endl<<a<<","<<b<<":"<<f<<","<<j<<endl;
    if(f == (j * n)) a = j;
    else b = j;
  }
  cout<<a * n<<endl;
}

