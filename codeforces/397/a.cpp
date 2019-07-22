#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
string str, ho;
map<string, int> ma;

void ini(void){
  //scanf("%d\n", &N);
  cin>>N>>ho;
  //cout<<ho<<endl;
  for(int i = 0; i < N; i++){
    cin>>str;
    //cout<<str.substr(0, 3)<<" "<<str.substr(5, 3)<<endl;
    if(str.substr(0, 3) == ho){
      ma[str.substr(5, 3)]++;
    }else{
      ma[str.substr(0, 3)]--;
    }
  }
}

bool sol(void){
  map<string, int>::iterator ite;
  for(ite = ma.begin(); ite != ma.end(); ite++){
    //cout<<ite->first<<","<<ite->second<<endl;
    if(ite->second > 0) return true;
  }
  return false;
}

int main(void){
  int i, j;

  ini();

  if(sol()) cout<<"contest"<<endl;
  else cout<<"home"<<endl;

}
