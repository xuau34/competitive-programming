#include <bits/stdc++.h>
using namespace std;
long long T, N, M, Q;
char str[105];
void ini(void){
  scanf("%s", str);
}

void sol(void){
  N = strlen(str);
  for(long long i = 0; i < N; ++i){
    if( str[i] >= 'a' && str[i] <= 'z' )
      T = i;
  }
  if( T ) cout << str << endl;
  else{
    for(int i = 0; i < N; ++i){
      if( str[i] >= 'a' && str[i] <= 'z' )
        cout << (char)toupper( str[i] );
      else cout << (char)tolower( str[i] );
    }
    cout << endl;
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
