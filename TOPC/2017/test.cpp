#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
vector<long long> a;
void ini(void){
  a.push_back(1);
  scanf("%d%d", &N, &M);
}

void sol(void){
  while(N--){
    for(long long i: a) printf("%1.lld ", i);
    printf("\n");
    vector<long long> b(a);
    a.clear();
    a.push_back(1);
    for(int i = 1, j = b.size(); i < j; ++i){
      if( (b[i - 1] + b[i]) % M == 0 ) a.push_back(0);
      else a.push_back(b[i - 1] + b[i]);
    }
    a.push_back(1);
  }
  for(long long i: a) printf("%1.lld ", i);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
