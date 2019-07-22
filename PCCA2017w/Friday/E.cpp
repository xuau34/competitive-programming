#include <bits/stdc++.h>
using namespace std;
int T, n, m, q;
vector<pair<int, int> > node[20005];
set<pair<int, pair<int, int> > > edge;
bool visit[20005];
void Min_spanning_tree(void){
    memset(visit, 0, sizeof(visit));
    set<pair<int, pair<int, int> > >::iterator ite;
    int i = 0, a, b, d;
    for(ite = edge.begin(); i < n - 1 && ite != edge.end(); ite++){
      a = (*ite).second.first;
      b = (*ite).second.second;
      if(!visit[a] || !visit[b]){
        d = (*ite).first;
        visit[a] = visit[b] = 1;
        node[a].push_back(make_pair(b, d));
        node[b].push_back(make_pair(a, d));
        i++;
      }
    }
}
int main(void){
  int i, j, a, b, d;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d %d", &n, &m, &q);
    edge.clear();
    for(i = 1; i <= n; i++) node[i].clear();
    for(i = 0; i < m; i++){
      scanf("%d %d %d", &a, &b, &d);
      //node[a].push_back(make_pair(b, d) );
      //node[b].push_back(make_pair(a, d) );
      edge.insert(make_pair(d, make_pair(a, b) ) );
    }

    Min_spanning_tree();

    
    for(i = 1; i <= n; i++){
      cout<<i<<"(a, d):";
      for(j = 0; j < node[i].size(); j++) printf("(%d, %d) ", node[i][j].first, node[i][j].second);
      cout<<endl;
    }
    /*
    cout<<"edge(d, a):";
    set<pair<int, int> >::iterator ite;
    for(ite = edge.begin(); ite != edge.end(); ite++){
      printf("(%d, %d) ", (*ite).first, (*ite).second);
    }
    cout<<endl;
    */
    for(i = 0; i < q; i++){
      scanf("%d", &j);
      //printf("%d\n", solve(j));
    }
  }
}
