#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[10000];
priority_queue<int> v;
void ini(void){
  cin >> N;
  T = N;
  while( N-- ){
    cin >> M;
    ++arr[M];
    /*
    if(arr[M] > 1){
      v.push( M );
    }
    */
  }
}

void sol(void){
  long long ans = 0;
  /*
  for(int i = T; i > 0; --i){
    if(!arr[i]){
      ans += abs(i - v.top());
      v.pop();
    }
  }
  */
  for(int i = 1; i < 10000; ++i){
    if(arr[i] > 1){
      ans += arr[i] - 1;
      arr[i + 1] += arr[i] - 1;
      arr[i] = 1;
    }
  }
  cout << ans << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
