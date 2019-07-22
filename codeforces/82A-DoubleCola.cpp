#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

int main(void){
  int i, j;
  scanf("%d", &N);
  if(N > 5){
    for(i = 1, T = j = 5; T + j * 2 < N;){
      j *= 2;
      T += j;
      i *= 2;
    }
    N -= T;
    N = ceil((double)N / (i * 2));
  }
  if(N == 1) printf("Sheldon\n");
  else if(N == 2) printf("Leonard\n");
  else if(N == 3) printf("Penny\n");
  else if(N == 4) printf("Rajesh\n");
  else printf("Howard\n");
}
