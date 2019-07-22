#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool a[105];
void ini(void){
  scanf("%d", &N);
  scanf("%d", &M);
  for(int i = 0; i < M; ++i){
    scanf("%d", &Q);
    a[Q] = 1;
  }
  scanf("%d", &M);
  for(int i = 0; i < M; ++i){
    scanf("%d", &Q);
    a[Q] = 1;
  }
}

void sol(void){
  for(int i = 1; i <= N; ++i){
    if(!a[i]){
      printf("Oh, my keyboard!\n");
      return;
    }
  }
  printf("I become the guy.\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
