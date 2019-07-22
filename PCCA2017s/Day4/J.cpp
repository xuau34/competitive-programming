#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int T, N, M, Q;
pair<long long, pair<long long, long long> > arr[40005];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%lld %lld %lld", &arr[i].first, &arr[i].second.first, &arr[i].second.second);
  }
  sort(arr, arr + N);
}

void sol(void){
  long long ans = 0;
  for(int i = 0; i < N; ++i){
    int j = 1;
    while( arr[i + j].first < arr[i].second.first ){
      if( arr[i + j].second.second > arr[i].second.second ){
        arr[i].second.first = arr[i + j].first;
      }else{
        arr[i + j].first = arr[i].second.first;
      }
      ++j;
    }
    //printf("(%d, %d)%d ", arr[i].first, arr[i].second.first, arr[i].second.second);
    ans += ( arr[i].second.first - arr[i].first) * arr[i].second.second;
  }
  printf("%lld\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
