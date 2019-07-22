#include <bits/stdc++.h>
using namespace std;
long long S, F, T, N;
map<long long, int> m;

void ini(void){
  int i;
  long long j;
  map<long long, int>::iterator ite;
  cin>>S>>F>>T>>N;
  for(i = 0; i < N; i++){
    cin>>j;
    ite = m.find(j);
    if(ite == m.end()) m[j] = 1;
    else m[j]++;
  }
}

void sol(void){
  long long i, j, peo = 0, ans, v = 1100000000000;
  for(i = 0; i < F; i++){
    peo += m[i];
    j = peo * T + S;
    if(j >= F) break;
    else j -= i;

    if(j < v){
      ans = i;
    //cout<<"i = "<<i<<", "<<"peo = "<<peo<<endl<<j<<" vs "<<v<<" => ans = "<<ans<<endl;
      v = j;
    }
  }
  cout<<ans<<endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
