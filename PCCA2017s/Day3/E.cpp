#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[105];
bool arr[1000];
void ini(void){
  scanf("%s", str);
}

void sol(void){
  N = strlen(str);
  for(int i = 0; i < N; ++i){
    if(!arr[ str[i] ]){
      ++M;
      arr[ str[i] ] = 1;
    }
  }
  if( M & 1 ) cout << "IGNORE HIM!" << endl;
  else cout << "CHAT WITH HER!" << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
