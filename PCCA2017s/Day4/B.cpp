#include <bits/stdc++.h>
using namespace std;
int T, N, M, K, l, r, arr[100005], ans[100005], storer[1000005];
pair< pair<int, int>, int> pii[100005];
vector<int> store[1000005];
void ini(void){
  scanf("%d %d %d", &N, &M, &K);
  for(int i  = 1; i <= N; ++i){
    scanf("%d", arr+i);
    arr[i] ^= arr[i - 1];
  }
  for(int i = 0; i < M; ++i){
    scanf("%d %d", &pii[i].first.first, &pii[i].first.second);
    pii[i].second = i;
  }
  sort(pii, pii + M);
}

void sol(void){
  l = pii[0].first.first, r = pii[0].first.first;
  int L, R;
  long long sum = 0;
  for(int i = 0; i < M; ++i){
    for(L = l; L < pii[i].first.first; ++L){
      sum -= store[ L ].size();
      for(int j : store[ L ]){
        --storer[j];
      }
      store[ L ].clear();
      //printf("0sum -= store[%d]( = %d)\n", L, store[L].size());
    }

    if(pii[i].first.second < r){
      ans[ pii[i].second ] = sum;
      for(int j = pii[i].first.second + 1; j <= r; ++j){
        ans[ pii[i].second ] -= storer[j];
        //printf("1ans -= storer[%d]( = %d)\n", j, storer[j]);
      }
      continue;
    }

    for(int j = l; j <= r; ++j){
      for(R = r; R <= pii[i].first.second; ++R){
        if( (arr[R] ^ arr[j - 1]) == K ){
          store[j].push_back(R);
          ++storer[R];
          ++sum;
        //printf("1arr[%d] ^ arr[%d] = %d => store[%d] = %d, sum = %d\n", R, j - 1, arr[R]^arr[j - 1], j, store[j], sum);
        }
      }
    }
    for(int j = r + 1; j <= pii[i].first.second; ++j){
      for(R = j; R <= pii[i].first.second; ++R){
        if( (arr[R] ^ arr[j - 1]) == K ){
          store[j].push_back(R);
          ++storer[R];
          ++sum;
        //printf("2arr[%d] ^ arr[%d] = %d => store[%d] = %d, sum = %d\n", R, j - 1, arr[R]^arr[j - 1], j, store[j], sum);
        }
      }
    }
    l = L;
    r = R;
    ans[ pii[i].second ] = sum;
  }
  for(int i = 0; i < M; ++i) printf("%d\n", ans[i]);
}

int main(void){
  int i, j;

  ini();

  sol();

}
