#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N;
int arr[100005];
int ans[100005];

void init() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%d", arr+i);
  memset(ans, -1, sizeof(ans));
}

void sol() {
  queue<int> q;
  ans[N-1] = 0;
  q.push(N-1);
  while(!q.empty()) {
    int t = q.front();
    printf("%d ", t);
    q.pop();
    if(t-arr[t] >= 0) {
      int tt = t - arr[t];
      if(ans[tt] == -1) {
        ans[tt] = ans[t] + 1;
        q.push(tt);
      }
      printf("(%d,%d) ", tt, ans[tt]);
    }
    if(t+arr[t] < N ) {
      int tt = t + arr[t];
      if(ans[tt] == -1) {
        ans[tt] = ans[t] + 1;
        q.push(tt);
      }
      printf("(%d,%d) ", tt, ans[tt]);
    }
    printf("\n");
  }
  for(int i=0; i<N; ++i) {
    printf("%d\n", ans[i]);
  }
}

int main() {
  freopen("jumping.in", "r", stdin);
  int T;
  scanf("%d", &T);
  while(T--) {
    init();
    sol();
  }
}
