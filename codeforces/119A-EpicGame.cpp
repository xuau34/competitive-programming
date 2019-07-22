#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j;
  scanf("%d %d %d", &i, &j, &N);
  while(N >= 0){
    if(__gcd(i, N) <= N) N -= __gcd(i, N);
    else{
      printf("1\n");
      return 0;
    }
    if(__gcd(j, N) <= N) N -= __gcd(j, N);
    else{
      printf("0\n");
      return 0;
    }
  }
}
