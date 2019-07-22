#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
pair<int, int> arr[1005];
void ini(void){
  cin >> N;
}

void sol(void){
  for(int i = 0; i < N; i++){
    cin >> arr[i].first >> arr[i].second;
    if(arr[i].first != arr[i].second){
      cout<<"rated"<<endl;
      return;
    }
  }
  for(int i = 1; i < N; i++){
    if(arr[i].first > arr[i - 1].first){
      cout << "unrated" << endl;
      return;
    }
  }
  cout << "maybe" << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
