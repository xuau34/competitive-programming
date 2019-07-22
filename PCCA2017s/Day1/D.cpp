#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str0[15], str1[15];
void ini(void){
  scanf("%s\n%s", str0, str1);
}

int get( int n, int i, bool b ){
  int ans = 0;
  n += (b)? 1: -1;
  if( i == N && n == Q) ++ans;
  if(i < N) ans += get( n, i + 1, 0) + get( n, i + 1, 1);
  return ans;
}

void sol(void){
  int len = strlen(str0), j = 1, k;
  for(int i = 0; i < len; ++i){
    if(str1[i] == '?') ++N, j <<= 1;
    else M += (str1[i] == '+')? 1: -1;
    T += (str0[i] == '+')? 1: -1;
  }
  Q = T - M;
  if(!Q && !N){
    printf("%.9f\n", (double)1);
    return;
  }
  k = get( 0, 1, 0 ) + get( 0, 1, 1);
  printf("%.9f\n", (double)k / j);
}

int main(void){
  int i, j;

  ini();

  sol();

}
