#include <bits/stdc++.h>
using namespace std;
int T, N, Q;
map<int, int> S, M;
void ini(void){
  char str[1005];
  int i;
  scanf("%d", &N);
  scanf("%s", str);
  for(i = 0; i < N; i++){
    S[(str[i] - '0')]++;
  }
  scanf("%s", str);
  for(i = 0; i < N; i++){
    M[(str[i] - '0')]++;
  }
}

void sol(void){
  int s = 0, m = 0;
  map<int, int>::iterator ite;
  for(pair<int, int> pii : S){
    if(M.find(pii.first) != M.end()){
      m += M[pii.first];
      printf("S %d M: %d x %d => m = %d\n", pii.first, pii.first, M[pii.first], m);
    }
  }
  for(pair<int, int> pii : S){
    ite = M.upper_bound(pii.first);
    if(ite != M.end()){
      printf("S: %d find: (%d, %d) => s = ", pii.first, ite->first, ite->second);
      s += ite->second;
      ite->second = 0;
      printf("%d, (%d, %d)\n", s, ite->first, ite->second);
    }
  }
  printf("%d\n%d\n", N - m, s);
}

int main(void){
  int i, j;

  ini();

  sol();

}
