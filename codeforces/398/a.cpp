#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool arr[100005];

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  int i, j, k;
  for(i = 0, j = N; i < N; i++){
    scanf("%d", &k);
    arr[k] = 1;

    if(k == j){
      while(arr[j]){
        printf("%d ", j);
        j--;
      }
    }

    printf("\n");

  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
