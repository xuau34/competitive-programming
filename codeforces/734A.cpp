#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[2];
char str[100005];
void ini(void){
  scanf("%d%s", &N, str);
  for(int i = 0; i < N; ++i){
    if(str[i] == 'A') ++arr[0];
    else ++arr[1];
  }
}

void sol(void){
  if(arr[0] > arr[1]) printf("Anton\n");
  else if(arr[0] < arr[1]) printf("Danik\n");
  else printf("Friendship\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
