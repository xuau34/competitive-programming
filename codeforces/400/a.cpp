#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
string arr[2], str[2];
void ini(void){
  for(int i = 0; i < 2; i++){
    cin>>arr[i];
  }
  cin>>N;
  for(int i = 0; i < 2; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void sol(void){
  int i, j;
  while(N--){
    for(i = 0; i < 2; i++) cin>>str[i];
    for(i = 0; i < 2; i++){
      if(arr[i] == str[0]){
        arr[i] = str[1];
      }
    }
    for(i = 0; i < 2; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
