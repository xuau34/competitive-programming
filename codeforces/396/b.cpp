#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005];
void ini(void){
  int i;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", arr+i);
  }
}

void sol(void){
  int i, j;
  sort(arr, arr+N);
  for(i = 2; i < N; i++){
    if(arr[i - 2] + arr[i - 1] > arr[i]){
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
