#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int T, N, M, Q;
pair<int, int> arr[1005];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d%d", &arr[i].first, &arr[i].second);
  sort(arr, arr + N);
  //for(int i = 0; i < N; ++i) printf("(%d, %d) ", arr[i].first, arr[i].second);
  //printf("\n");
}

void sol(void){
  int right = arr[0].second;
  long long ans = arr[0].second - arr[0].first;
    //printf("%d, %lld\n", right, ans);
  for(int i = 1; i < N; ++i){
    if(arr[i].second <= right) continue;
    if(arr[i].first <= right){
      ans += arr[i].second - right;
    }else{
      ans += arr[i].second - arr[i].first;
    }
    right = arr[i].second;
    //printf("%d, %lld\n", right, ans);
  }
  printf("%lld\n", ans);
}

int main(void){
  int i, j;

  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
