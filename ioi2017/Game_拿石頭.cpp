#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int T, N, M, Q;
long long SG[MAXN];

long long _MEX(const set<long long> *x){
  int mex = 0;
  set<long long >::iterator ite;
  for(ite = (*x).begin(); ite != (*x).end(); ite++){
    //cout<<*ite<<","<<mex<<" ";
    if(*ite != mex) return mex;
    mex++;
  }
  //cout<<" => "<<mex<<endl;
  return mex;
}

long long _SG(long long x){ //SG > 0, win; SG == 0, lose;
  if(x <= 1000000 && SG[x] >= 0) return SG[x];
  if(x > 0){
  //cout<<"_SG("<<x<<")"<<endl;
    set<long long> temp;
    //cout<<x<<" "<<x - 1<<" "<<x - 1ull<<"!";
    temp.insert(_SG(x - 1ull));
  //while(1);
    temp.insert(_SG(x - 2ull));
    for(int i = 1; i < x - 1; i++){
      temp.insert(_SG(i) ^ _SG(x - i - 1ull));
      temp.insert(_SG(i) ^ _SG(x - i - 2ull));
    }
    //printf("SG[%d]: ", x);
    if(x > 1000000) return _MEX(&temp);
    return SG[x] = _MEX(&temp);
  }
}

int main(void){
  int i, j;
  long long a, ans, b = 0;
  memset(SG, -1, sizeof(SG));
  SG[0] = 0;
  scanf("%d", &T);
  while(T--){
    scanf("%d %lld", &N, &a);
    for(i = 0; i <= N; i++){
      printf("SG[%d]: %d\n", i, _SG(i));
    }
    for(; b <= a; b++) _SG(b);
    ans = _SG(a);
    cout<<"ans"<<ans<<endl;
    for(i = 1; i < N; i++){
      scanf("%lld", &a);
      for(; b <= a; b++) _SG(b);
      ans ^= _SG(a);
    }
    if(ans) printf("F\n");
    else printf("S\n");
  }
  
}
