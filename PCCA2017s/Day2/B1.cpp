#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[500][500];

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  char str[15];
  int len;
  for(int i = 0; i < N; ++i){
    scanf("%s", str);
    len = strlen( str );
    for(int j = 'a'; j <= 'z'; ++j){
      if( arr[ j ][ str[0] ] )
        arr[ j ][ str[ len - 1 ] ] = max( arr[ j ][ str[ len - 1 ] ], arr[ j ][ str[0] ] + len );
    }
    arr[ str[0] ][ str[len - 1] ]  = max( arr[ str[0] ][ str[len - 1] ], len );

    /*
    for(int i = 'a'; i <= 'z'; ++i){
      for(int j = 'a'; j <= 'z'; ++j)
        printf("%d ", arr[i][j]);
      printf("\n");
    }
      printf("\n");
      printf("\n");
      */
  }
  for(int i = 'a'; i <= 'z'; ++i) Q = max(Q, arr[i][i]);
  printf("%d\n", Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
