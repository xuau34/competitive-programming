#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005];

void ini(void){
  cin>>N>>M;
  for(int i = 0; i < N; i++) cin>>arr[i];
}

void sol(void){
  long long sum = 0, r = 0;
  sort(arr, arr + N);
  for(int i = 0; i < N; ){
    r++;
    arr[i] -= M;
    if(r == 2){
      sum ++;
      r = 0;
    }
    i = (arr[i] <= 0)? i+1: i;
  }
  cout<<sum + r<<endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
