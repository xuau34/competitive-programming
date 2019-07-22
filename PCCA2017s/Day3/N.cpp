#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
priority_queue<int> q;
void ini(void){
  cin >> N >> M;
  while(N--){
    cin >> Q;
    if(Q < 0)q.push( ( Q * -1 ) );
  }
}

void sol(void){
  long long sum = 0;
  while(M-- && !q.empty()){
    sum += q.top();
    q.pop();
  }
  cout << sum << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
