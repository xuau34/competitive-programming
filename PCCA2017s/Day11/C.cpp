#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005];
long long sum, ans;
bool v[100005];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", arr + i);
  }
}

void sol(void){
  sort(arr, arr + N);
  for(int i = 0; i < N; ++i){
    if(arr[i] >= sum) ++ans, sum += arr[i];
  }
  printf("%lld\n", ans);

}

int main(void){
  int i, j;

  ini();

  sol();

}
