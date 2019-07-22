#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
int T, N, M, Q, subt[MAXN];
long long dis[MAXN];  //to root
vector<int> node[MAXN];

int dfs_ini(int x, int p){
  dis[x] = dis[p] + 1;
  int i = 1, j;
  for(int v: node[x]){
    if(v != p){
      j = dfs_ini(v, x);
      i += j;
      subt[x] = (subt[x] < j)? j: subt[x];
    }
  }
  subt[x] = (subt[x] < N - i)? N - i: subt[x];
  return i;
}

int Centroid(int x){
  vector<pair<int, int> > temp;
  for(int v: node[x]){
    temp.push_back(make_pair(subt[v], v));
  }
  sort(temp.begin(), temp.end());
  return temp[0].second;
}

/*void dfs_cen(int x, int p){
  for(int v: node[x]){
    
  }
}*/

int main(void){
  int i, j, k;
  scanf("%d", &T);
  while(T--){
    memset(subt, 0, sizeof(subt));
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) node[0].push_back(i);
    for(i = 0; i < M; i++){
      scanf("%d %d", &j, &k);
      node[j].push_back(k);
      node[k].push_back(j);
    }

    int root = 1;
    dis[root] = 0;
    dfs_ini(root, root);
    //cout<<Centroid(0)<<endl;
    //dfs_cen();

    cout<<"subt: ";
    for(i = 1; i <= N; i++) cout<<subt[i]<<" ";
    cout<<endl<<"dis: ";
    for(i = 1; i <= N; i++) cout<<dis[i]<<" ";
    cout<<endl;
  }
}
