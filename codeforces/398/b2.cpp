#include <bits/stdc++.h>
using namespace std;
long long S, F, T, N;

void ini(void){
  cin>>S>>F>>T>>N;
}

void sol(void){
  if(!N){
    cout<<S<<endl;
    exit(0);
  }
  long long i, j, k = 0, l, peo = 0, ans = 0, v = S;
  for(i = 0; i < N; i++){
    cin>>j;
    if(!i){
      ans = j - 1;
      v = S - j + 1;
    }
    peo++;
    if(!k) k = j;
    else if(k != j){
      l = (peo - 1) * T + S;
      //cout<<l<<" vs "<<j<<", ";
      if(l > (F - T)) break;
      else if(l < j){
        ans = l;
        v = 0;
        break;
      }else l -= (j - 1);
      //cout<<l<<" vs "<<v<<", ";
      if(l < v){
        ans = j - 1;
        v = l;
      }
      //cout<<"ans = "<<ans<<", v = "<<v<<endl;
      k = j;
    }
  }
  if(i == N){
    l = peo * T + S;
    //cout<<l<<" vs "<<j<<", ";
    if(l <= (F - T)){
      ans = F - T;
    }
  }
  cout<<ans<<endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
