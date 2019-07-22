#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, K;

void ini(void){
  scanf("%d%d%d%d%d", &T, &N, &M, &Q, &K);
}

void sol(void){
  long long x = (Q << 1) + N * T, y = (K << 1) + M * T;
  if(x == y) printf("Friendship\n");
  else if(x > y) printf("Second\n");
  else printf("First\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
