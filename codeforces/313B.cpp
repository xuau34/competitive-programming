#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, pre[(int)1e5+10];
char str[(int)1e5+10];
void ini(void){
  scanf("%s", str);
  N = strlen(str);
  for(int i = 1; i + 1 <= N; ++i){
    pre[i] = pre[i - 1];
    if(str[i - 1] == str[i]) ++pre[i];
  }
  scanf("%d", &M);
}

void sol(void){
  while(M--){
    scanf("%d%d", &T, &Q);
    printf("%d\n", pre[Q - 1] - pre[T - 1]);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
