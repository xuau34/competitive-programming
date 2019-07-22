#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
}

int sol(void){
  char pre[100005], str[100005];
  scanf("%s", pre);
  long long flip = arr[0], notflip = 0;
  int pren = strlen(pre), strn;
  for(int i = 1, x, y; i < N; ++i){
    scanf("%s", str);
    if(pren > (strn = strlen(str)) || (notflip < 0 && flip <0) ) return -1;
    if(pren < strn){
      x = notflip;
      y = min(flip, notflip) + arr[i];
    }else{
    }
    if(notflip >= 0){
      if(str >= pre) x = notflip;
      else y = notflip + arr[i];
    }
    if(flip >= 0){
      if()
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
