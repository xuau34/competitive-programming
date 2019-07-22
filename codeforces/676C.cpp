#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, Q;
char str[100005];

void ini(void){
  scanf("%d%d", &N, &M);
  scanf("%s", str);
}

inline bool check(int x){
  int arr[5];
  memset(arr, 0, sizeof(arr));
  for(int i = 0; i < x; ++i) ++arr[ str[i] - 'a' ];
  if(arr[0] >= x - M || arr[1] >= x - M) return true;
  for(int i = x; i < N; ++i){
    ++arr[ str[i] - 'a' ];
    --arr[ str[i - x] - 'a' ];
    if(arr[0] >= x - M || arr[1] >= x - M) return true;
  }
  return false;
}

void sol(void){
  int l = 0, r = N + 1, m;
  while(r - l > 1){
    m = (l + r) >> 1;
    if( check(m) ) l = m;
    else r = m;
    //printf("(%d, %d, %d)\n", l, m, r);
  }
  printf("%d\n", l);
}

int main(void){
  int i, j;

  ini();

  sol();

}
