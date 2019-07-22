#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, day[200005], ans[200005];
long long pre[200005];
pair< pair<int, int>, int> pii[200005];
priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= M; ++i){
    scanf("%d", day + i);
    pre[i] = pre[i - 1] + day[i];
    que.push( make_pair( day[i], i ) );
  }
  for(int i = 0; i < N; ++i) scanf("%d%d", &pii[i].first.first, &pii[i].first.second), pii[i].second = i;
  sort(pii, pii + N);
}

struct Node{
  long long sum, d;
  int v;
};
struct Node no[200005];
void add( int i, int x ){
  while(i <= M){
    no[i].sum += x;
    ++no[i].d;
    i += i & -i;
  }
}
pair<long long, long long> sum( int i ){
  long long ret = 0, re = 0;
  while(i){
    ret += no[i].sum;
    re += no[i].d;
    i &= (i - 1);
  }
  return make_pair(ret, re);
}

void sol(void){
  int l, r, m;
  pair<long long, long long> pll;
  for(int i = 0; i < N; ++i){
    while( !que.empty() && que.top().first <= pii[i].first.first ){
      add( que.top().second, que.top().first );
      que.pop();
    }
    l = 0, r = M + 1; //(,]
    while(r - l > 1){
      m = (l + r) >> 1;
      pll = sum(m);
      if( (pre[m] - pll.first - (m - pll.second) * pii[i].first.first) >= pii[i].first.second ) r = m;
      else l = m;
    }
    ans[ pii[i].second ] = (r > M)? 0: r;
  }
  for(int i = 0; i < N; ++i) printf("%d ", ans[i]);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
