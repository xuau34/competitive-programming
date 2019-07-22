#include <bits/stdc++.h>
using namespace std;
int main(void){
  string str;
  char S0[105], S1[105];
  cin >> str;
  int num = 0, len = str.length();
  for(int i = 0; i < len; i++){
    if( isupper( str[i] ) ) ++num;
    S0[i] = tolower( str[i] );
    S1[i] = toupper( str[i] );
  }
  S0[len] = S1[len] = 0;
  if( num > str.length() >> 1 ) cout << S1 << endl;
  else cout << S0 << endl;
}
