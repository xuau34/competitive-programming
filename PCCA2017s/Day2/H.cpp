#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, Q, tag[300005], L, R, C, col[300005], ans;
void build(int i, int l, int r){ //[,)
  col[i] = 2;
  if( r - l == 1 ) return;
  int m = (l + r) >> 1;
  build( i << 1, l, m );
  build( i << 1 | 1, m, r );
}

void refresh(int i){
  int l = i << 1, r = i << 1 | 1;
  col[i]= col[l] | col[r];
}

void push(int i){
  int l = i << 1, r = i << 1 | 1;
  col[l] = col[r] = 1 << tag[i];
  tag[l] = tag[r] = tag[i];
  tag[i] = 0;
}

bool color(int i, int l, int r){
  if( r <= L || l >= R ){ /***/
    return 0;
  }
  if( L <= l && r <= R ){
    tag[i] = C;
    col[i] = 1 << C;
    return 1;
  }else if(r - l > 1){
    if(tag[i]) push(i); /***/
    int m = (l + r) >> 1;
    if( color(i << 1, l, m) | color(i << 1 | 1, m, r) ){  //pull, everytime
      refresh(i);
      return 1;
    }
  }
}

void query(int i, int l, int r){
  if( r <= L || l >= R ) return; /***/
  if( L <= l && r <= R ){
    ans |= col[i];
  }else if( r - l > 1 ){
    if(tag[i]) push(i); /***/
    int m = (l + r) >> 1;
    query(i << 1, l, m);
    query(i << 1 | 1, m, r);
  }
  
}

void ini(void){
  scanf("%d %d %d", &N, &M, &Q);
  build( 1, 1, N + 1 );
}

void sol(void){
  char c[10];
  int sum;
  while( Q-- ){
    scanf("%s", c);
    if( c[0] == 'C' ){
      scanf("%d %d %d", &L, &R, &C);
      if(L > R){  /***/
        sum = L;
        L = R;
        R = sum;
      }
      ++R;
      color(1, 1, N + 1);
    }else{
      scanf("%d %d", &L, &R);
      if(L > R){
        sum = L;
        L = R;
        R = sum;
      }
      ++R; sum = ans = 0;
      query(1, 1, N + 1);
      while(ans){
        sum += ans & 1;
        ans >>= 1;
      }
      printf("%d\n", sum);
    }
  }

}

int main(void){
  int i, j;

  ini();
  sol();

}
