#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
double sum;
bool v[100005];
vector< int > no[100005];
void ini(void){
  scanf("%d", &N);
  no[1].push_back(0), v[0] = 1;
  for(int i = 1; i < N; ++i){
    scanf("%d%d", &M, &Q);
    no[M].push_back(Q);
    no[Q].push_back(M);
  }
}

void sol(int x, long long l, double p){
  v[x] = 1;
  bool f = 0;
  for(int i = 0, j = no[x].size(); i < j; ++i)
    if(!v[no[x][i]]) sol(no[x][i], l + 1, p / (j - 1)), f = 1;
  if(!f){
    sum += p * l;
  }
  //printf("sol(%d, %lld, %lf) => sum = %lf\n", x, l, p, sum);
}

int main(void){
  int i, j;

  ini();

  sol(1, 0, 1);

  printf("%.9lf\n", sum);
}
