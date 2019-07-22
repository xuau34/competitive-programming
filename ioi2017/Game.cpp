#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
int T, N, M, Q, SG[MAXN];

int _MEX(set<int> *x){
  int mex = 0;
  set<int>::iterator ite;
  for(ite = (*x).begin(); ite != (*x).end(); ite++){
    cout<<*ite<<","<<mex<<" ";
    if(*ite != mex) return mex;
    mex++;
  }
  cout<<endl;
  return mex;
}

int _SG(int x){ //SG > 0, win; SG == 0, lose;
  if(SG[x] >= 0) return SG[x];
  set<int> temp;
  temp.insert(_SG(x - 1));
  return SG[x] = _MEX(&temp);
}

int main(void){
  int i, j;
  memset(SG, -1, sizeof(SG));
}
