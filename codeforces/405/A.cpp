#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;

void ini(void){
  cin>>N>>M;
  for(T = 1; N <= M; T++){
    N *= 3;
    M <<= 1;
    //cout<<N<<","<<M<<endl;
  }
  cout<<T - 1<<endl;
}

void sol(void){

}

int main(void){
  int i, j;

  ini();

  sol();

}
