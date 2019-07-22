#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[(int)1e5+10], suf[(int)1e5+10];
bool uni[(int)1e5+10];
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i); 
  for(int i = N - 1; i >= 0; --i){
    suf[i] = suf[i + 1];
    if( uni[arr[i]] ) continue;
    ++suf[i], uni[arr[i]] = true;
  } 
}

void sol(void){
  while(M--){
    scanf("%d", &Q);
    printf("%d\n", suf[Q - 1]);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
