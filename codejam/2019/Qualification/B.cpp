#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
void ini(void){
  cin >> N;
}

string sol(void){
  string str;
  cin >> str;
  for(int i = 0, len = str.length(); i < len; ++i){
    if( str[i] == 'S' ) str[i] = 'E';
    else str[i] = 'S';
  }
  return str;
}

int main(void){
  cin >> T;
  for( int Case = 1; Case <= T; ++Case ){

    ini();

    cout << "Case #" << Case << ": " << sol() << endl;
  }

}
