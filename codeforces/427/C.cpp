#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long ret[11];
struct Node{
  long long sum[11]/*, d*/;
  //int v;
} no[105][105];

void add( int i, int x, int X ){  //y, c, x
  while(i <= 100){
    ++no[X][i].sum[x];
    i += i & -i;
  }
}
void sum( int i, int X, int k ){
  while(i){
    //printf("\t%d:", i);
    for(int j = 0; j < 11; ++j){
      ret[j] += k * no[X][i].sum[j];
      //printf("\t\tret[%d] = %lld(%lld), ", j, ret[j], no[X][i].sum[j]);
    }
    //printf("\n");
    i &= (i - 1);
  }
}

void ini(void){
  int x, y, c;
  scanf("%d%d%d", &N, &Q, &M);
  for(int i = 0; i < N; ++i){
    scanf("%d%d%d", &x, &y, &c);
    add(y, c, x);
  }
}

void sol(void){
  int t, x, y, X, Y;
  for(int i = 0; i < Q; ++i){
    scanf("%d%d%d%d%d", &t, &x, &y, &X, &Y);
    long long ans = 0;
    memset(ret, 0, sizeof(ret));
    for(int i = x; i <= X; ++i){
      sum(Y, i, 1);
      //printf("sum(%d, %d, 1): ", Y, i);
      //for(int j = 1; j < 11; ++j)
      //  printf("ret[%d] = %lld ", j, ret[j]);
      //printf("\n");

      sum(y - 1, i, -1);
      //printf("sum(%d, %d, 1): ", y - 1, i, -1);
      //for(int j = 1; j < 11; ++j)
      //  printf("ret[%d] = %lld ", j, ret[j]);
      //printf("\n");
    }
    for(int j = 0; j < 11; ++j){
      //printf("ret[%d] = %lld\n", j, ret[j]);
      ans += ( (j + t) % (M + 1) ) * ret[j];
    }
    printf("%lld\n", ans);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
