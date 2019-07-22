#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[1000];
string str;
void ini(void){
  cin >> N >> str;
  M = str.size();
  for(int i = 0 ;i < M; ++i){
    ++arr[ str[i] ];
  }
}

void sol(void){
  vector<char> ans;
  for(int i = 'a'; i <= 'z'; ++i){
    if(arr[i] % N != 0){
      cout << "-1" << endl;
      return;
    }else{
      for(int j = 0; j < arr[i] / N; ++j){
        ans.push_back(i);
      }
    }
  }
  for(int j = 0; j < N; j++){
  for(int i = 0; i < ans.size(); ++i){
    cout << (char)ans[i];
  }
  }
  cout << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
