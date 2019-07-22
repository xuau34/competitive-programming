#include <bits/stdc++.h>
using namespace std;
int T, N, M, K;
char str[30];
void ini(void){
  scanf("%s %d", str, &K);
}

void sol(void){
  int i, get = 0, ans = 0, length = strlen(str);
  for(i = length - 1; i >= 0 && get < K; i--){
    if(str[i] == '0'){
      get++;
    }else{
      ans++;
    }
    //printf("str[%d] = %c => get = %d, ans = %d\n", i, str[i], get, ans);
  }
  if(get != K){
    printf("%d\n", length - 1);
  }else printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
