#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
int arr[125][5], suc[5];
double _exp = 0.0000000001;
void ini(void){
  cin >> N;
  memset(suc, 0, sizeof(suc));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < 5; j++){
      cin >> arr[i][j];
      if(arr[i][j] >= 0) ++suc[j];
    }
  }
}

bool check(long long X){
  long long tmp, res = 0, rew = 3000;
  double b = 0, d = 1/32, l, r;
  for(int i = 0; i < 5; i++){
    l = (double)suc[i] / (N + X);
    if(arr[0][i] >= 0) r = (double)(suc[i] + X) / (N + X);
    else r = l;
    tmp = -1000000007;
    b = 0;
    d = (double)1/32;
    rew = 3000;
    while( rew ){
      //printf("d = %.5lf l = %.5lf r = %.5lf\n", d, l, r);
      if( (l + _exp >= d && l - _exp <= d) ||  ((l < d ) && (r > b ))  ){
        tmp = max(tmp,(long long)( rew * ((arr[0][i] >= 0)? 1 - (double)arr[0][i] / 250 : 0) -
                       rew * ((arr[1][i] >= 0)? 1 - (double)arr[1][i] / 250 : 0)    ));
  cout << "check "<<X<<" ";
        cout<<i << "th: rew ="<<rew<<" d ="<<d<<" (l, r) = ("<<l<<","<<r<<") tmp = "<<tmp<<endl; 
      }
      b = d;
      d *= 2;
      rew -= 500;
    }
    if( tmp > -1000000007) res += tmp;
  }
    //cout << "res="<<res<<endl;
  return res > 0;
}

void sol(void){
  long long l = -1, r = 1000010000, m;
  while( l + 1 < r ){
    m = (l + r) >> 1;
    //cout<<l<<","<<r<<" check("<<m<<")"<<endl;
    if(check(m)) r = m;
    else l = m;
  }
    //cout<<l<<","<<r<<endl;
  if(r > 1000000007) cout<<"-1"<<endl;
  else cout << r << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
