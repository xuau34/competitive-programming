#include <bits/stdc++.h>
using namespace std;
int T, Q;
long long N, M;

vector<int> prim;
bool prim_[46345];

void build(){
  fill(prim_, prim_ + 46345, 1);
  prim_[0] = prim_[1] = 0;
  for(int i=2;i<46345;i++)if(prim_[i]){
    prim.push_back(i);
    for(int j = i*i ; j<46345 ; j+=i)
      prim_[j] = 0;
  }
}

inline bool is_pr(int x){
  if(x < 46345) return prim_[x];
  for(int i=0;i<prim.size() && prim[i]*prim[i]<=x ; i++) if(x % prim[i] == 0)
    return 0;
  return 1;
}

void ini(void){
  scanf("%d", &T);
  build();
}

void sol(void){
  long long x;
  for(int i = 0; i < T; ++i){
    scanf("%lld%lld", &N, &M);
    for(x = N; x <= M; ++x){
      if(is_pr(x)) printf("%lld\n", x);
    }
    if(i < T - 1) printf("\n");
  }
}

int main(void){

  ini();
  sol();

}
