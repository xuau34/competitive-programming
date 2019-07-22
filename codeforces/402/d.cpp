#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, mov[200005];
string a, b;
bool took[200005];
void ini(void){
  int i;
  cin>>a>>b;
  N = a.length();
  M = b.length();
  for(i = 0; i < N; i++){
    cin>>mov[i];
    mov[i]--;
  }
}

bool check(int x){
  int i, j = 0;
  for(i = 0; i < x; i++){
    took[ mov[i] ] = 1;
  }
  i = 0;
  while(i < N && j < M){
    if(!took[i] && a[i] == b[j]) j++;
    i++;
  }
  memset(took, 0, sizeof(took));
  if(j == M) return true;
  else return false;
}

void sol(void){
  int l = 0, r = N, m;
  while(l + 1 < r){
    m = (l + r)>>1;
    if(check(m)) l = m;
    else r = m;
  }
  printf("%d\n", l);
}

int main(void){
  int i, j;

  ini();

  sol();

}
