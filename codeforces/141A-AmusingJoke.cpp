#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[105];
int arr[30][2];
int main(void){
  int i, j;
  scanf("%s", str);
  for(i = 0, j = strlen(str); i < j; i++){
    arr[(int)(str[i] - 'A')][0]++;
  }
  scanf("%s", str);
  for(i = 0, j = strlen(str); i < j; i++){
    arr[(int)(str[i] - 'A')][0]++;
  }
  scanf("%s", str);
  for(i = 0, j = strlen(str); i < j; i++){
    arr[(int)(str[i] - 'A')][1]++;
  }
  for(i = 0; i < 30; i++){
    if(arr[i][0] != arr[i][1]){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}
