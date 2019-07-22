#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N, M, Q, arr[100];

void ini(void){
  char str[105];
  scanf("%d%s", &M, str);
  //printf("!!!!%s\n", str);
  N = 0;
  memset(arr, 0, sizeof(arr));
  for(int l = strlen(str), i = 0; i < l; ++i){
    if( isdigit( str[i] ) ){
      while( i < l && isdigit( str[i] )) arr[N] = (arr[N] * 10) + str[i++] - '0';
      ++N;
    }
  }
  //for(int i = 0; i < N; ++i) printf("%d ", arr[i]);
  //printf("\n");
}

void sol(void){
  bool s = 0;
  for(int i = 0; ((i << 1) + 2) < N; ++i){
    if( abs( arr[(i << 1) + 1] - arr[i] ) <= M ){
      if(s) printf(" ");
      else s = 1;
      printf("%c%c", (i + 'A'), (i << 1) + 1 + 'A');
    }
    if( abs( arr[(i << 1) + 2] - arr[i] ) <= M ){
      if(s) printf(" ");
      else s = 1;
      printf("%c%c", (i + 'A'), (i << 1) + 2 + 'A');
    }
  }
  printf("\n");
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
