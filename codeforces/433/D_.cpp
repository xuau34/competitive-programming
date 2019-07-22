#include <bits/stdc++.h>
using namespace std;
int T, N, M, K, Q, go[100005], BI[100005][2];
vector< pair<int, int> > arr[1000005]; //[day] = city, cost
vector< pair<int, int> > back[100005]; //[city] = c, day
void ini(void){
  memset(go, -1, sizeof(go));
  scanf("%d%d%d", &N, &M, &K);
  for(int i = 0, d, s, t, c; i < M; ++i){
    scanf("%d%d%d%d", &d, &s, &t, &c);
    if(t == 0) arr[d].push_back(make_pair(s, c));
    else back[t].push_back( make_pair(c, d) );
    if(Q < d) Q = d;
  }
  for(int i = 1; i <= N; ++i) sort(back[i].begin(), back[i].end()), BI[i][1] = back[i].size();
}

void sol(void){
  long long ans = 5e12;
  int b = 0;
  for(int i = 1; i <= N; ++i) if(!back[i].empty()) ++b;
  for(int i = 1, s = 0; i + K < Q && b == N; ++i){
    bool f = false;
    for(pair<int, int> &j: arr[i]){ //只有當前面的變少，答案才可能變更好。
      if(go[j.first] > j.second) go[j.first] = j.second, f = true;
      else if(go[j.first] < 0) ++s, go[j.first] = j.second, f = true;
    }
    if(s == N && f){
      long long temp = 0;
      for(int j = 1; j <= N && temp < ans; ++j){
        while(BI[j][0] < BI[j][1] && back[j][ BI[j][0] ].second <= i + K) ++BI[j][0];
        if(BI[j][0] < BI[j][1]) temp += back[j][ BI[j][0] ].first + go[j];
        else{
          --b;
          break;
        }
      }
      if(b == N) ans = min(ans, temp);
    }
  }
  if(ans < 5e12) printf("%lld\n", ans);
  else printf("-1\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
