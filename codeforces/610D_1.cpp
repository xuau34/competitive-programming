/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 200005 //因一個存成兩個 => 陣列開不夠大 -> TLE
int n;
struct node{
  int x1, x2, y, type;
  node(){};
  node(int _x1, int _x2, int _y, int _type): x1(_x1), x2(_x2), y(_y), type(_type){}
  bool operator<(const node &b) const{
    return y < b.y;
  }
} e[maxn];
int h[maxn];
int len[maxn << 3], cover[maxn << 3];

void push_up(int l, int r, int t){
  if(cover[t] > 0) len[t] = h[r] - h[l];
  else{
    if(l == r) len[t] = 0;
    else len[t] = len[t << 1] + len[t << 1 | 1];
  }
}
void update(int L, int R, int l, int r, int t, int v){
  if(l == r) return;
  if(L <= l && R >= r) cover[t] += v;
  else{
    int mid = (l + r) >> 1;
    if(mid > L) update(L, R, l, mid, t << 1, v);
    if(mid < R) update(L, R, mid, r, t << 1 | 1, v);
  }
  push_up(l, r, t);
}
int main(void){
  while(~scanf("%d", &n)){
    int res = 0, x1, y1, x2, y2;
    for(int i = 1; i <= n; ++i){
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      if(x1 > x2 || y1 > y2) swap(x1, x2), swap(y1, y2);
      --x1, --y1;
      e[res] = node(x1, x2, y1, 1), h[res++] = x1;
      e[res] = node(x1, x2, y2, -1), h[res++] = x2;
      //e[res].x1 = x1, e[res].x2 = x2, e[res].y = y1, e[res].type = 1, h[res++] = x1;
      //e[res].x1 = x1, e[res].x2 = x2, e[res].y = y2, e[res].type = -1, h[res++] = x2;
    }
    sort(h, h + res);
    res = unique(h, h + res) - h;
    //int Res = 1;
    //for(int i = 1; i < res; ++i) if(h[i] > h[i - 1]) h[Res++] = h[i];
    //res = Res;
    //memset(len, 0, sizeof(len));
    //memset(cover, 0, sizeof(cover));
    sort(e, e + (n << 1));
    ll ans = 0;
    int L, R;
    for(int i = 0, j = (n << 1) - 1; i < j; ++i){
      L = lower_bound(h, h + res, e[i].x1) - h;
      R = lower_bound(h, h + res, e[i].x2) - h;
      update(L, R, 0, res - 1, 1, e[i].type);
      ans += 1ll * len[1] * (e[i + 1].y - e[i].y);  //這裡如果是1LL的話會MLE
    }
    printf("%I64d\n", ans);
  }
}
