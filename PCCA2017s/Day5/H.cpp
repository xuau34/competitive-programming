#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int T, N, M, Q, arr[100005], cnt[200005], cn[100005], ans[100005];
pair< pair<int, int>, int> pii[100005];
inline bool cmp( pair< pair<int, int>, int> &a, pair< pair<int, int>, int> &b){
  return (a.first.first/Q == b.first.first/Q)?( ( (a.first.first/Q) & 1 )? a.first.second < b.first.second: a.first.second > b.first.second): a.first.first/Q < b.first.first/Q;
}
void ini(void){
  memset(cnt, 0, sizeof(cnt));
  memset(cn, 0, sizeof(cn));
  Q = sqrt( (double) N );
  scanf("%d", &M);
  for(int i = 1; i <= N; ++i) scanf("%d", arr + i), arr[i] += 100000;
  for(int i = 0; i < M; ++i){
    scanf("%d %d", &pii[i].first.first, &pii[i].first.second);
    pii[i].second = i;
  }
  sort(pii, pii + M, cmp);
}

void sol(void){
  int l = pii[0].first.first, r = pii[0].first.first, L, R, mx = 1;
  ++cn[ ++cnt[ arr[l] ] ];
  for(int i = 0; i < M; ++i){
    L = pii[i].first.first, R = pii[i].first.second;
    while(l < L){
      --cn[ cnt[ arr[l] ]-- ];
      ++cn[ cnt[ arr[l] ] ];
      ++l;
    }
    //printf("l < L (%d, %d) => %d\n", l,r, mx);
    while(l > L){
      --cn[ cnt[ arr[ --l ] ]++ ];
      ++cn[ cnt[ arr[l] ] ];
      mx = max(mx, cnt[ arr[l] ]);
    }
    //printf("l > L (%d, %d) => %d\n", l,r, mx);
    while(r < R){
      --cn[ cnt[ arr[ ++r ] ]++ ];
      ++cn[ cnt[ arr[r] ] ];
      mx = max(mx, cnt[ arr[r] ]);
    }
    //printf("r > R (%d, %d) => %d\n", l,r, mx);
    while(r > R){
      --cn[ cnt[ arr[r] ]-- ];
      ++cn[ cnt[ arr[r] ] ];
      --r;
    }
    while( mx > 0 && !cn[ mx ] ) --mx;
    //printf("r < R (%d, %d) => %d\n", l,r, mx);
    ans[ pii[i].second ] = mx;
  }
  for(int i = 0; i < M; ++i) printf("%d\n", ans[i]);
}

int main(void){
  int i, j;
  while( scanf("%d", &N) == 1 && N){
    ini();
    sol();
  }
}
