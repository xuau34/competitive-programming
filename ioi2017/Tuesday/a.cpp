#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long ps[100005];
vector<int> node[100005];

long long dfs(int x){
  long long s = 0, S = 0, temp;
  for(int i: node[x]){
    temp = dfs(i);
    S += s * temp;
    s += temp;
  }
  ps[x] = s + S;
  //printf("ps[%d] = %lld  + %lld\n", x, s, p);
  node[x].clear();
  return s + 1;
}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for(i = 2; i <= N; i++){
      scanf("%d", &j);
      node[j].push_back(i);
    }
    /*
    for(i = 1; i <= N; i++){
      cout<<i<<" : ";
      for(int v: node[i]) cout<<v<<" ";
      cout<<endl;
    }
    */
    dfs(1);
    /*
    for(i = 1; i <= N; i++) cout<<ps[i]<<" ";
    cout<<endl;
    */
    for(i = 1; i <= N; i++){
      printf("%lld", ps[i] * 2 + 1);
      if(i != N) printf(" ");
    }
    printf("\n");
    memset(ps, 0, sizeof(ps));
  }
}
