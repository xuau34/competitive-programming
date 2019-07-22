#include <iostream>
#include <utility>
using namespace std;
int T, N, M, Q, L, R, arr[50005], seg0[150005], seg1[150005];

void build(int x, int l, int r){
  if(r - l == 1){
    seg0[x] = seg1[x] = arr[l];
    return;
  }
  int m = (l + r) >> 1;
  build(x << 1, l, m);
  build(x << 1 | 1, m, r);
  seg0[x] = min( seg0[x << 1], seg0[x << 1 | 1]);
  seg1[x] = max( seg1[x << 1], seg1[x << 1 | 1]);
}

void ini(void){
  scanf("%d %d", &N, &Q);
  for(int i = 1; i <= N; ++i) scanf("%d", arr + i);
  build(1, 1, N + 1);
}

pair<int, int> query(int x, int l, int r){
  if(r <= L || l >= R) return make_pair(1000000, -1000000);
  if(L <= l && r <= R){
    return make_pair( seg0[x], seg1[x] );
  }else if(r - l > 1){
    int m = (l + r) >> 1;
    pair<int, int> a = query(x << 1, l, m), b = query(x << 1 | 1, m, r);
    a.first = min(a.first, b.first);
    a.second = max(a.second, b.second);
    return a;
  }
}

void sol(void){
  pair<int, int> pii;
  while(Q--){
    scanf("%d %d", &L, &R);
    ++R;
    pii = query(1, 1, N + 1);
    printf("%d\n",  pii.second - pii.first);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
