#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

struct PT{
  int x, y, ex, ey;
} pt[100005];

struct SEG{
  struct SEG *l, *r;
  int sum;
  SEG(){
    l = r = NULL;
    sum = 0;
  }
} *root;

inline bool _cmp(const struct PT &X, const struct PT &Y){
    return X.y < Y.y;
  }
inline bool cmp(const struct PT &X, const struct PT &Y){
    return (X.x == Y.x)? X.y < Y.y: X.x < Y.x;
}

priority_queue<struct PT, vector<struct PT>, function<bool(struct PT, struct PT)> > que(_cmp);

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d%d%d%d", &pt[i].x, &pt[i].y, &pt[i].ex, &pt[i].ey);
  sort(pt, pt + N, cmp);
  for(int i = 0; i < N; ++i) printf("%d %d %d %d\n", pt[i].x, pt[i].y, pt[i].ex, pt[i].ey);
  root = new struct SEG;
}
int L, R;
bool update(int l, int r, struct SEG *&x, bool n){
  if(l >= R || r <= L) return;
  if(L <= l && r <= R){
    if(n && x == NULL){
      x = new struct SEG;
      x -> sum = 1;
    }else delete(x);
    return 1;
  }else if(r - l > 1){
    
  }
}

void sol(void){
  for(int i = 0; i < N; ++i){
    que.push(pt[i]);
    if(que.top().ex == i){
      L = que.top().y;
      R = que.top().ey;
      update(-1e9, 1e9 + 1, root, 0);
    }
  }

}

int main(void){
  int i, j;

  ini();

  sol();

}
