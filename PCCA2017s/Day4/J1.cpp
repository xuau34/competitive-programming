#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int T, N, M, Q;
map< pair<long long, long long>, long long >m;
void ini(void){
  scanf("%d", &N);
  pair<long long, long long> pii;
  for(int i = 0; i < N; ++i){
    scanf("%lld %lld %d", &pii.first, &pii.second, &Q);
    m[pii] = max( m[pii], Q );
  }
}

void sol(void){
  long long ans = 0;
  map< pair<long long, long long>, long long>::iterator ite = m.begin(), te;
  while(ite != m.end()){
    te = ite;
    while( ( *(++te) ).first.first < (*ite).first.second ){
      if( (*te).second > (*ite).second ){
        arr[i].second.first = arr[i + j].first;
      }else{
        arr[i + j].first = arr[i].second.first;
      }
      ++j;
    }
    //printf("(%d, %d)%d ", arr[i].first, arr[i].second.first, arr[i].second.second);
    ans += ( arr[i].second.first - arr[i].first) * arr[i].second.second;
    ++ite;
  }
  printf("%lld\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
