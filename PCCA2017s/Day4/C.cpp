#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, L, R, arr[50005];
long long seg[200005];

int build(int x, int l, int r){
  if(r - l <= 1) return seg[x] = arr[l];
  int m = (l + r) >> 1;
  seg[x] += build(x << 1, l, m);
  seg[x] += build(x << 1 | 1, m , r);
  return seg[x];
}


void ini(void){
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i){
    scanf("%d", arr + i);
  }
  build(1, 1, N + 1);
}

long long query(int x, int l, int r){
  if(r <= L || l >= R) return 0;
  if(L <= l && r <= R){
    return seg[x];  
  }else if(r - l > 1){
    int m = (l + r) >> 1;
    return query(x << 1, l, m) + query(x << 1 | 1, m, r);
  }
}

void add(int x, int l, int r){
  if(r <= L || l >= L + 1) return;
  if(L <= l && r <= L + 1){
    seg[x] += R;
  }else if(r - l > 1){
    int m = (l + r) >> 1;
    add(x << 1, l, m);
    add(x << 1 | 1, m, r);
    seg[x] = seg[x << 1] + seg[x << 1 | 1];
  }
}

void sol(void){
  char str[10];
  while( scanf("%s", str) && str[0] != 'E'){
    if(str[0] == 'Q'){
      scanf("%d %d", &L, &R);
      ++R;
      printf("%lld\n", query(1, 1, N + 1) );
    }else if(str[0] == 'A'){
      scanf("%d %d", &L, &R);
      add(1, 1, N + 1);
    }else if(str[0] == 'S'){
      scanf("%d %d", &L, &R);
      R *= (-1);
      add(1, 1, N + 1);
    }
    /*
    for(int i = 1; i <= N * 4; ++i) printf("%d ", seg[i]);
    printf("\n");
    */
  }
}

int main(void){
  int i, j;
  scanf("%d", &T);
  for(i = 1; i <= T; ++i){
    printf("Case %d:\n", i);
    ini();
    sol();
    memset(seg, 0, sizeof(seg));
  }
}
