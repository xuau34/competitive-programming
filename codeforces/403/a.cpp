#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[200005], ch[200005];

void ini(void){
  int i;
  scanf("%d", &N);
  for(i = 0, N <<= 1; i < N; i++){
    scanf("%d", arr+i);
  }
}

void sol(void){
  int i, ans, count;
  for(i = ans = count = 0; i < N; i++){
    if(ch[ arr[i] ] == 0){
      count++;
      ch[ arr[i] ] = 1;
      if(count > ans) ans = count;
    }else if(ch[ arr[i] ] == 1){
      count--;
      ch[ arr[i] ] = 2;
    }
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
