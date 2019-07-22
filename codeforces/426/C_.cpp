#include <bits/stdc++.h>
#include <stdlib.h>
#define Time 15
using namespace std;
int T, N, M, Q, p[46345];
long long ans;

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

inline long long findfac(long long x, int y){
  long long ret = 0;
  for(int i=0;i<prim.size() && x > 1; ++i){
    while(x > 1 && x % prim[i] == 0){
      p[ prim[i] ] += y;
      ret += y;
      x /= prim[i];
    }
  }
  return ret;
}

void ini(void){
  scanf("%d%d", &N, &M);
  memset(p, 0, sizeof(p));
}

bool sol(void){
  long long x, y, z = 0;
  while( ( Q = __gcd(N, M) ) > 1 ){
    z += findfac(Q, 2);
    N /= Q;
    M /= Q;
  }
  x = y = z;
  if(N > 1) x += findfac(N, 1);
  if(M > 1) y += findfac(M, 1);
  if(x > y) swap(x, y);
  if(x << 1 < y) return 0;
  for(int i = 0; i < 46345; ++i) if(p[i] % 3 != 0) return 0;
  return 1;
}

int main(void){
  long long i;
  
  build();
  /*
  while(cin>>i){
    cout<<Miller_Rabin(i)<<endl;
  }
  */
  scanf("%d", &T);
  while(T--){
    ini();
    if( sol() ) printf("Yes\n");
    else printf("No\n");
  }


}
