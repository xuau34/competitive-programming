#include <bits/stdc++.h>
using namespace std;
//1e9 < 2^30
int T, N, K, arr[100005];

void ini(void){
  scanf("%d%d", &N, &K);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
  sort(arr, arr + N);
}

int search(int L, int R, int x, int shift){
  int l = L, r = R, m, temp = (1<<x) - 1;
  while( r - l > 1 ){
    m = (l + r) >> 1;
    printf("(%d, %d): %d vs %d\n", l, r, arr[m] - shift, temp);
    if( arr[m] - shift <= temp ) l = m;
    else r = m;
  }
  cout << endl;
  return l + 1;
}

int sol(void){
  int ret = 0, L = 0, R = N;
  for(int i = 30, l, r; i > -1; --i){
    l = search(L - 1, R, i, ret);
    r = search(L, R, i + 1, ret);
    printf("i = %d, L R  = %d, %d vs %d, %d\n", i, L, R, l, r);
    if( r - l >= K ){
      ret |= 1<<i;
      L = l, R = r;
    }
    for(int j = l; j < r; ++j) arr[j] -= 1<<i;
    sort(arr + L, arr + R);
    for(int j = 0; j < N; ++j){
      cout << arr[j] << " ";
    }
    cout << endl;
    printf("ret = %d\n", ret);
  }
  return ret;
}

int main(void){

  ini();

  printf( "%d\n", sol() );

}
