#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10005;
int v[MAX_N], p, m, t, deg[MAX_N], PA[MAX_N], Comp[MAX_N];
vector<int> node[MAX_N];
bool visit[MAX_N];
queue<int> q;
int comp(int x){
  int i, sum;
  visit[x] = 1;
  for(i = 0, sum = 1; i < node[x].size(); i++){
    if(!visit[node[x][i]] && deg[node[x][i]] >= 0){
      PA[node[x][i]] = PA[x];
      sum += comp(node[x][i]);
    }
  }
  //printf("%d: PA = %d\n", x, PA[x]);
  return sum;
}
int main(void){
  int i, a, b;
  long long ans;
  scanf("%d", &t);
  while(t--){
    memset(visit, 0, sizeof(visit));
    memset(deg, 0, sizeof(deg));
    scanf("%d %d", &p, &m);
    for(i = 1; i <= p; i++) scanf("%d", v + i);
    for(i = 0; i < m; i++){
      scanf("%d %d", &a, &b);
      node[a].push_back(b);
      node[b].push_back(a);
    }
    
    
    for(i = 1, ans = 0; i <= p; i++){
      deg[i] =node[i].size();
      if(node[i].size() < 2) q.push(i);
    }

    while(!q.empty()){
      a = q.front();
      deg[a] = -1;
      for(i = 0; i < node[a].size(); i++){
        if(deg[node[a][i]] >= 0){
          deg[node[a][i]]--;
          if(deg[node[a][i]] < 2) q.push(node[a][i]);
        }
      }
      q.pop();
    }
    

    /*
    for(i = 1; i <= p; i++){
      cout<<i<<":";
      for(int j = 0; j < node[i].size(); j++) cout<<node[i][j]<<" ";
      cout<<endl;
    }
    */

    for(i = 1; i <= p; i++){
      if(deg[i] >= 0){
        if(visit[i]){
          a = Comp[PA[i]];
        }else{
          PA[i] = i;
          a = comp(i);
          Comp[PA[i]] = a;
        }
        //printf("PA[%d] = %d => %d\n", i, PA[i], a);
        if(a & 1) ans += v[i];
      }
      node[i].clear();
    }

    /*
    for(i = 1; i <= p; i++) cout<<i<<","<<PA[i]<<" ";
    cout<<endl;
    */

    cout<<ans<<endl;
  }
}
