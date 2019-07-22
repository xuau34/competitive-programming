#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, F[100005], G[100005], H[100005], Hi[100005];

void ini(void){
  M = 0;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    scanf("%d", F + i);
    if(!G[ F[i] ]){
      G[ F[i] ] = 1;
      H[ ++M ] = F[i];
      Hi[ F[i] ] = M;
    }
  }
}

int sol(void){
  int i;
  memset(G, 0, sizeof(G));
  for(i = 1; i <= N; i++){
    G[i] = Hi[ F[i] ];
  }
  for(i = 1; i <= M; i++){
    if(G[H[i]] != i){
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", M);
  for(i = 1; i <= N; i++){
    printf("%d", G[i]);
    if(i != N) printf(" ");
    else printf("\n");
  }
  for(i = 1; i <= M; i++){
    printf("%d", H[i]);
    if(i != M) printf(" ");
    else printf("\n");
  }
  return 0;
}

int main(void){
  int i, j;

  ini();

  sol();

}
