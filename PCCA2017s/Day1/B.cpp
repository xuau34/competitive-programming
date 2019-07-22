#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool arr[100005];
map<int, int> m;
void ini(void){
  scanf("%d %d", &N, &Q);
  for(int i = 2; i < 100005; ++i){
    if( m.find(i) != m.end() ) continue;
    m[i] = i;
    for(int j = i; j < 100005; j += i) m[j] = i;
  }
}

void check( void ){
  if( m[M] == M ){
    printf("Success\n");
    arr[M] = 1;
  }else{
    fprintf( stderr, "%d\n", m[M] );
    int i = M / m[ M ];     // M / m[M]; float point exception
    while( m[ i ] != i ){
      if( arr[i] ){
        printf("Conflict with %d\n", i);
        return;
      }
      i = i / m[ i ];
    }
    if( arr[i] ){
      printf("Conflict with %d\n", i);
      return;
    }
    printf("Success\n");
  }
}

void sol(void){
  char c[10];
  int i;
  while(Q--){
    scanf("%s %d", c, &M);
    printf("c = %s, M = %d\n", c, M);
    if(c[0] == '+'){
      if(arr[M]) printf("Already on\n");
      else check();
    }else{
      if(arr[M]) printf("Success\n");
      else printf("Already off\n");
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
