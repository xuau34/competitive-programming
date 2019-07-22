#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, y[4005];
pair<int, int> pii[4005];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d%d", &pii[i].first, &pii[i].second);
    if(pii[i].second > pii[i].first){
      M = pii[i].second;
      pii[i].second = pii[i].first;
      pii[i].first = M;
    }
  }
  sort(pii, pii + N, greater<pair<int, int> >() );
}

void sol(void){
  long long ans = 0, temp, X, Y, x = 1000005;
  for(int i = 0; i < N; ++i){
    x = min(x, (long long)pii[i].first);
    y[i] = pii[i].second;
    sort(y, y + i + 1);
    //printf("x = %lld y: ", x);
    for(int j = 0; j <= i; ++j){
      temp = x * y[j] * (i - j + 1);
      if(temp > ans){
        ans = temp;
        X = x;
        Y = y[j];
      }
      //ans = max(ans, x * y[j] * (i - j + 1));
      //printf("(%d, %d) ", j, y[j]);
    }
    //printf("=> ans = %lld\n", ans);
  }
  printf("%lld\n%lld %lld\n", ans, X, Y);
}

int main(void){
  int i, j;

  ini();

  sol();

}
