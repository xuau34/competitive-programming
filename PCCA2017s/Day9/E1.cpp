#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005][2];
pair<int, int> pii[100005];
vector< pair<int, int> > vii;
void ini(void){
  arr[0][0] = pii[0].second = 1, arr[0][1] = pii[0].first = 1000000000;
  for(int i = 1; i <= N; ++i)scanf("%d%d", arr[i], arr[i] + 1), pii[i].first = arr[i][1], pii[i].second =arr[i][0];
}

void sol(void){
  sort(pii, pii + N + 1);
  int x, y;
  for(int i = 0; i <= N; ++i){
    printf("pii[%d] = (%d, %d)\n", i, pii[i].first, pii[i].second);
  }
  for(int i = 1; i <= N; ++i) printf("%d %d\n", arr[i][0], arr[i][1]);
  vii.clear();
}

int main(void){
  int i, j;
  while(scanf("%d", &N) && N){
    ini();
    sol();
  }
}
