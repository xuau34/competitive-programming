#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool arr[3005];
void ini(void){
  scanf("%d", &N);
}

void sol(void){
  int p, x; 
  for(int X = 6; X <= N; ++X){
    x = X;
    p = 0;
    for(int i = 2; x > 1 && p < 3; ++i){
      if( x % i == 0 ){
        ++p;
        do{
          x /= i;
        }while( (x % i) == 0 );
      }
    }
    if( p == 2 ) ++T;
  }
  cout << T << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
