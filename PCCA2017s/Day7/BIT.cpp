#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
struct Node{
  long long sum, d;
  int v;
};
struct Node no[MAXN];
void add( int i, int x ){
  while(i <= N){
    no[i].sum += x;
    i += i & -i;
  }
}
long long sum( int i ){
  long long ret = 0;
  while(i){
    ret += no[i].sum;
    i &= (i - 1);
  }
  return ret;
}
void ini(void){
  scanf("%d", &N);

}

void sol(void){

}

int main(void){
  int i, j;

  ini();

  sol();

}
