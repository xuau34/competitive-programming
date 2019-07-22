//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <cstring>
#include <algorithm>
//#include <functional>
using namespace std;
const int MAXN = 150500;
int T, k, m, q, t, p, V[MAXN], ans[MAXN]/*, Q[MAXN]*/;
pair<int, int> OP[MAXN];
string str[MAXN];
class cmp{
  public:
    bool operator() (const pair<int, int>& x, const pair<int, int>& y) const {
      return ((x.first == y.first)? (x.second > y.second): (x.first < y.first));
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
int main(void){
  int i, j, ii, jj;
  char ss[201];
  scanf("%d", &T);
  while(T--){
    scanf("%d %d %d", &k, &m, &q);
    for(i = 1; i <= k; i++){
      scanf("%s %d", ss, V + i);
      str[i] = ss;
    }
    for(i = 1; i <= m; i++) scanf("%d %d", &OP[i].first, &OP[i].second);
    sort(OP + 1, OP + m + 1);
    i = 1;
    for(ii = jj = 1; ii <= m; ii++){
      t = OP[ii].first;
      p = OP[ii].second;

      for(j = jj; j <= t; j++){
        pq.push(make_pair(V[j], j));
      }
      while(!pq.empty() && p){
        ans[i++] = pq.top().second;
        p--;
        pq.pop();
      }
      jj = t + 1;
    }
    for(j = jj; j <= k; j++)
      pq.push(make_pair(V[j], j));

    while(!pq.empty()){
      ans[i++] = pq.top().second;
      pq.pop();
    }

    for(i = 0; i < q; i++){
      scanf("%d", &j);
      printf("%s", str[ans[j]].c_str());
      if(i != q - 1) printf(" "); 
    }
    printf("\n");
  }
}
