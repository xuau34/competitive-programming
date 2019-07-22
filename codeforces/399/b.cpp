#include <bits/stdc++.h>
using namespace std;
long long T, N, L, R;

void ini(void){
  cin>>N>>L>>R;
  for(T = 1; T <= N; T<<=1ull);
  //cout<<T<<"!"<<endl;
}

long long sol(long long x, long long l, long long r){
  long long y = (l + r)>>1ull, ans = 0;
  if(L <= y && y <= R && x & 1) ans++;

  if(L <= l && y - 1 <= R) ans += (x>>1ull);
  else if(l <= y - 1 && !(R < l || y - 1 < L))
    ans += sol(x>>1ull, l, y - 1);

  if(L <= y + 1 && r <= R) ans += (x>>1ull);
  else if(y + 1 <= r && !(R < y + 1 || r < L))
    ans += sol(x>>1ull, y + 1, r);
  
  //cout<<x<<" ("<<l<<","<<r<<") "<<ans<<endl;
  return ans;
}

int main(void){
  int i, j;

  ini();

  cout<<sol(N, 1, T - 1)<<endl;

}
