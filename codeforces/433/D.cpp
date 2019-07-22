#include <bits/stdc++.h>
using namespace std;
int T, N, M, K, Q, go[100005];

class node{
  public:
    int s, t, c;
    node(int x, int y, int z):s(x), t(y), c(z){}
};
vector<node> arr[1000005];
deque<pair<int, int> > back[100005]; //day, c
void ini(void){
  memset(go, -1, sizeof(go));
  scanf("%d%d%d", &N, &M, &K);
  for(int i = 0, d, s, t, c; i < M; ++i){
    scanf("%d%d%d%d", &d, &s, &t, &c);
    arr[d].push_back(node(s, t, c));
    if(Q < d) Q = d;
  }
  for(int i = K + 1, k; i <= Q; ++i){
    for(node &j: arr[i]){
      if(j.t == 0) continue;
      k = j.t;
      while(!back[k].empty() && back[k].back().second > j.c ) back[k].pop_back();
      back[k].push_back( make_pair(i, j.c) );
    }
  }
  /*
    printf("back: ");
    for(int j = 1; j <= N; ++j) printf("(%d, %d) ", back[j].front().first, back[j].front().second);
    printf("\n");
    */
}

void sol(void){
  long long ans = 5e12;
  for(int i = 1; i <= Q; ++i){
    for(node &j: arr[i]){
      if(j.t != 0) continue;
      if(go[j.s] < 0 || go[j.s] > j.c) go[j.s] = j.c;
    }
    long long temp = 0;
    int s = 0;
    for(int j = 1; j <= N; ++j){
      while(!back[j].empty() && back[j].front().first <= i + K) back[j].pop_front();
      if(go[j] > 0 && !back[j].empty()){
        ++s;
        temp += back[j].front().second + go[j];
      }
    }
    /*
    printf("%d:\ngo: ", i);
    for(int j = 1; j <= N; ++j) printf("%d ", go[j]);
    printf("\nback: ");
    for(int j = 1; j <= N; ++j) printf("(%d, %d) ", back[j].front().first, back[j].front().second);
    printf("\ntemp = %lld, s = %d => ans = %lld\n", temp, s, ans);
    */
    if(s == N) ans = min(ans, temp);
  }
  if(ans < 5e12) printf("%lld\n", ans);
  else printf("-1\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
