#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
priority_queue<int, vector<int>, greater<int> > p[4];
void ini(void){
  scanf("%d", &N);
  for(int i = 1; i <= N; ++i) scanf("%d", &M), p[M].push(i);
}

void sol(void){
  printf("%d\n", min(p[1].size(), min(p[2].size(), p[3].size()) ) );
  while(!p[1].empty() && !p[2].empty() && !p[3].empty()){
    printf("%d %d %d\n", p[1].top(), p[2].top(), p[3].top());
    p[1].pop(), p[2].pop(), p[3].pop();
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
