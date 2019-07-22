#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char arr[510];
bool check[30];

void ini(void){
  scanf("%s", arr);
}

bool sol(void){
  int i, j = strlen(arr);
  for(i = 0; i < j; i++){
    if(arr[i] != 'a' && !check[arr[i] - 'a' - 1]) return false;
    check[arr[i] - 'a'] = 1;
  }
  /*
  for(i = 1, j = check[0]; i < 26; i++){
    cout<<check[i]<<" vs j="<<j<<endl;
    if(check[i] && !j) return false;
    j &= check[i];
  }
  */
  return true;
}

int main(void){
  int i, j;

  ini();

  if(sol()) printf("YES\n");
  else printf("NO\n");

}
