#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
map<multiset<int>, int> m;
void ini(void){

}

void sol(void){
  map<multiset<int>, int>::iterator ite;
  T = 0;
  while(1){
    scanf("%d", &N);
    multiset<int> s;
    while(N--){
      scanf("%d", &M);
      s.insert(M);
    }
    ite = m.find(s);
    if(ite == m.end()) m[s] = T++;
    else{
      printf("---\n");
      for(ite = m.begin(); ite != m.end(); ite++){
        s = ite -> first;
        for(int v: s){
          printf("%d ", v);
        }
        printf(": %d\n", ite->second);
      }
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
