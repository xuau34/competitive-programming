/*
  Design a program that will send out a different string each time.
  And it will follow the alphabet order to send.
  eg:
    a, b, c, ..., z, aa, ab, ac, ...

  Toughts:
    Deal it like add.
 */

#include "bits/stdc++.h"
using namespace std;

string ReverseStr( string S ){
  for(int i = 0, j = S.length() - 1; i < j; ++i, --j ){
    swap(S[i], S[j]);
  }
  return S;
}

string StringIndex( void ){
  static string S;
  if( S.empty() ){
    S.push_back( 'a' );
    return S;
  }
  int carry = S[0] == 'z';
  S[0] = (S[0] - 'a' + 1) % 26 + 'a';
  for( int i = 1; carry && i < S.length(); ++i ){
    carry = S[i] == 'z';
    S[i] = (S[i] - 'a' + 1 + carry) % 26 + 'a'; 
  }
  if( carry ) S.push_back( 'a' );
  return ReverseStr( S );
}

int main(void){
  bool conn = true;
  while( cin >> conn ){
    for(int i = 0; i < 26; ++i) cout << StringIndex() << endl;
  }
  return true;
}
