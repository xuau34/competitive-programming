#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, c[2], p[2];
void ini(void){
  int a, b;
  c[0] = p[0] = -1;
  c[1] = p[1] = 2147483640;
  cin>>N;
  while(N--){
    cin>>a>>b;
    c[0] = max(c[0], a);
    c[1] = min(c[1], b);
  }
  cin>>N;
  while(N--){
    cin>>a>>b;
    p[0] = max(p[0], a);
    p[1] = min(p[1], b);
  }
  //cout<<c[0]<<" "<<c[1]<<" ; "<<p[0]<<" "<<p[1]<<endl;
  a = c[0] - p[1];
  b = p[0] - c[1];
  //cout<<a<<","<<b<<endl;
  if(a < 0 && b < 0) cout<<"0"<<endl;
  else cout<<max(a, b)<<endl;
}

void sol(void){

}

int main(void){
  int i, j;

  ini();

  sol();

}
