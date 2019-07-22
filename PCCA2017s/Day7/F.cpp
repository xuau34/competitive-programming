#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, cnt[105];
pair<int, int> pii[105];
inline bool cmp( pair<int, int> &A, pair<int, int> &B){
  return (A.second == B.second)? A.first > B.first: A.second < B.second;
}
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d%d", &pii[i].first, &pii[i].second );
  sort(pii, pii + N, cmp);
}

bool check( int x ){
  memset( cnt, 0, sizeof(cnt) );
  for(int i = 0; i <= 10000; ++i){
    for(int j = 0; j < N ; ++j) if( pii[j].first <= i && pii[j].second > i && cnt[j] < x ){
      ++cnt[j];
      break;
    }
  }
  /*
  printf("check(%d): ", x);
  for(int i = 0; i < N; ++i) printf("(%d,%d) ", i, cnt[i]);
  printf("\n");
  */
  for(int i = 0; i < N; ++i) if(cnt[i] < x) return 0;
  return 1;
}

void sol(void){
  int l = 0, r = 10001;
  while( r - l > 1 ){
    int m = (l + r) >> 1;
    //printf("(l, r) = (%d, %d) ", l, r);
    if( check(m) ) l = m;
    else r = m;
  }
  printf("%d\n", l * N);
}

int main(void){
  int i, j;

  ini();

  sol();

}
