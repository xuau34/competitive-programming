#include <bits/stdc++.h>
using namespace std;

vector< pair<int,int> > seg;
int T, N;

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> T;
  while(T--) {
    cin >> N;
    for (int i=0; i<N; ++i) {
      int l, x, u, d;
      cin >> l >> x >> u;
      seg.push_back(make_pair(x, x+l));
    }
    sort(seg.begin(),seg.end());
    int cnt=1;
    int lm=seg[0].first; // [!? -> )
    int rm=seg[0].second; // )
    for (int i=1; i<seg.size(); ++i) {
      if (seg[i].first>=rm) { // new one
        ++cnt;
        rm = seg[i].second;
      }
    }
    seg.clear();
    cout << cnt << '\n';
  }
  return 0;
}
