#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int T, N, M, Q;
bool arr[5][55], query[5];

void ini(void){
  char c;
  memset(arr, 0, sizeof(arr));
  scanf("\n");
  for(int k = 0, x = 0; k < 5; ++k){
    while( scanf("%c", &c) ){
      if( isdigit( c ) ) x = x * 10 + (c - '0');
      else{
        arr[k][x] = 1;
        //printf("c = %c, %d~ ", c, x);
        x = 0;
        if(c == '\n') break;
      }
    }
    //printf("\n");
  }
  /*
  for(int i = 0; i < 5; ++i){
    printf("%c: ", i + 'A');
    for(int j = 0; j < 33; ++j) if(arr[i][j]) printf("%d ", j);
    printf("\n");
  }
  */
}

void sol(void){
  char c;
  scanf("%d", &Q);
  while( Q-- ){
    scanf("%d", &M);
    memset(query, 0, sizeof(query));
    for(int i = 0; i < M; ++i) scanf(" %c", &c), query[c - 'A'] = 1;
    int ans = 0;
    for(int i = 0, j; i < 33; ++i){
      for(j = 0; j < 5; ++j) if( arr[j][i] != query[j] ) break;
      if(j != 5) continue;
      if(ans){
        printf("I don't know!\n");
        ans = 33;
        break;
      }
      ans = i;
    }
    if(ans == 33) continue;
    if(!ans) printf("Impossible!\n");
    else printf("%d\n", ans);
  }
}

int main(void){
  scanf("%d", &T);
  while(T--){
  ini();
  sol();
  }
}
