#include <bits/stdc++.h>
using namespace std;
long long T, N, n, m, Q;

void ini(void){
  cin>>n>>m;
}

inline bool get(long long x){
  if(x >= (n<<1)) return 0;
  if(x * x >= (n<<1)) return 0;
  return ((x * x) + x + (m<<1)) < ((n<<1));
}

void sol(void){ //(]
  long long l = 0, r = 1000000000000000000, mid;
  while(l < (r - 1)){
    mid = (l + r)>>1;
    Q = get(mid);
    cout<<l<<","<<r<<":"<<mid<<","<<Q<<endl;
    if(get(mid)){
      l = mid;
    }else{
      r = mid;
    }
  }
    cout<<l<<","<<r<<":"<<mid<<","<<Q<<endl;
  cout<<r+m<<endl;
}

int main(void){
  int i, j;

  ini();

  if(n <= m){
    cout<<n<<endl;
    return 0 ;
  }
  sol();

}
