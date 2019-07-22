#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005];
long long pre[100005], pos[100005];
void ini(void){
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) scanf("%d", arr + i), pre[i] = arr[i] + pre[i - 1];
  sort(arr + 1, arr + N + 1);
  for(int i = 1; i <= N; ++i) pos[i] = arr[i] + pos[i - 1];
}

void sol(void){
  scanf("%d", &M);
  int x, y, z;
  while(M--){
    scanf("%d%d%d", &x, &y, &z);
    if(x == 1) printf("%lld\n", pre[z] - pre[y - 1]);
    else printf("%lld\n", pos[z] - pos[y - 1]);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
