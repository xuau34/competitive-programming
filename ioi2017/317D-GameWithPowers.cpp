#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
map<int, bool> m;

bool td(void){
  map<int, bool>::iterator it;
  int i, j;
  bool ans = 0;
  for(it = m.begin(); it != m.end(); it++){
    i = it->first;
    if(it->second){
      if(i == 1){
        m[i] = 0;
        j = N + 1;
      }else j = 1;
        cout<<j<<" ";
      while(j <= N){
        m[j] = 0;
        j *= i;
      }

      ans |= (td()^1);

      if(it->first == 1){
        m[i] = 1;
        j = N + 1;
      }else j = 1;
      while(j <= N){
        m[j] = 1;
        j *= i;
      }
    }
  }
  for(it = m.begin(); it != m.end(); it++){
    if(it->second) cout<<it->first<<" ";
  }
  cout<<" => "<<ans<<endl;
  return ans;
}

int main(void){
  int i, j;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) m[i] = 1;
  cout<<td()<<endl;
}
