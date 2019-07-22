#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[(int)1e5+10];
int pre[(int)1e5+10];
void ini(void){
  scanf("%s", str);
  N = strlen(str);
  pre[0] = (str[0] == 'B' && str[1] == 'A');
  for(int i = 1; i + 1 < N; ++i){
    pre[i] = pre[i - 1] + (str[i] == 'B' && str[i + 1] == 'A');
  }
  pre[N] = pre[N - 1] = pre[N - 2];
}

bool sol(void){
  for(int i = 0; i + 1 < N; ++i){
    if(str[i] != 'A' || str[i + 1] != 'B') continue;
    printf("i = %d, pre[i - 2] = %d, pre[N] - pre[i + 1] = %d - %d\n", i, pre[i - 2], pre[N], pre[i + 1] );
    if( ( i > 1 && pre[i - 2] ) || pre[N] - pre[i + 1]) return true;
  }
  return false;
}

int main(void){
  int i, j;

  ini();

  if( sol() ) printf("YES\n");
  else printf("NO\n");

}
