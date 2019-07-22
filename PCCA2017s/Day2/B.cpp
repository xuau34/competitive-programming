#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[500];
char str[500005][15];
map< char, map<char, int> > m;
void ini(void){
  scanf("%d", &N);
}

void sol(void){
  int len, ans = 0;
  for(int i = 0; i < N; ++i){
    scanf("%s", str[i]);
    len = strlen(str[i]);
    
    if( m.find( str[i][0] ) != m.end() ) for( pair<char, int> j : m[ str[i][0] ] ){
      m[ str[i][len - 1] ][ j.first ] = max( m[ str[i][len - 1] ][ j.first ], j.second + len );
      if( j.first == str[i][len - 1] ) arr[ j.first ] = max( arr[ j.first ], j.second + len );
    }

    if( str[i][0] == str[i][len - 1] ) arr[ str[i][0] ] = max( arr[ str[i][0] ], len);
    m[ str[i][ len - 1 ] ][ str[i][0] ] = max( m[ str[i][ len - 1 ] ][ str[i][0] ], len );

    /*
    for(pair< char, map<char, int> > pii: m){
      printf("%c: ", pii.first);
      for( pair<char, int> j : pii.second ){
        printf("(%c, %d) ", j.first, j.second);
      }
    }
    printf("//");
    for(int i = 'a'; i <= 'z'; ++i) printf("%d ", arr[i]);
    printf("\n");
    */
  }
  for(int i = 'a'; i <= 'z'; ++i) ans = max( ans, arr[i] );
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
