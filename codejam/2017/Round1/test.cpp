#include <bits/stdc++.h>
using namespace std;
int main(void){
  long long T, i, N, M;
  string str;
  scanf("%d\n", &T);
  for(i = 1; i <= T; i++){
    scanf("%d %d\n", &N, &M);
    cout<<"Case #"<<i<<": "<<N<<","<<M<<endl;
    for( int j = 1; j <= N; j++){
    getline(cin, str);
    cout<<"Case #"<<i<<": "<<str<<endl;
    }
    for( int j = 1; j <= M; j++){
    getline(cin, str);
    cout<<"Case #"<<i<<": "<<str<<endl;
    }
  }
}
