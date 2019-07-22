#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, ans[300005], arr[300005];
priority_queue< pair<int, int> > pri;
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; ++i) scanf("%d", arr + i);
  for(int i = 1; i <= M; ++i) pri.push( make_pair(arr[i], i) );
}

void sol(void){
  long long sum = 0;
  for(int i = 1; i <= N; ++i){
    if(i + M <= N) pri.push( make_pair(arr[i + M], i + M) );
    ans[pri.top().second] = i + M;
    sum += (long long)(i + M - pri.top().second) * pri.top().first;
    pri.pop();
  }
  printf("%lld\n", sum);
  for(int i = 1; i <= N; ++i) printf("%d ", ans[i]);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
