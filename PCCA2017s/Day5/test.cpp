#include <bits/stdc++.h>
using namespace std;
int main(void){
  int A, B;
  while(cin >> A >> B){
    long long sum = 1;
    for(long long j = B, x = A, y = 1; j ; j >>= 1, y = y * (x + 1), x *= x ){
      if(j & 1){
        sum = sum * x + y;
      }
      printf("j = %lld => %lld %lld %lld\n", j, sum, x, y);
    }
  }
    /*
  long long sum = 1;
  for(long long j = 10, x = 2; j ; j >>= 1, x = x* x){
    if(j & 1){
      sum = sum*x;
    }
      printf("j = %d => %d %d\n", j, sum, x);
  }
  */
}
