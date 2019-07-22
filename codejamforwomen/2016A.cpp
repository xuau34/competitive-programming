#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
map<int, int> ma;
vector<int> ans;
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < (N<<1); i++){
    scanf("%d", &M);
    ma[M]++;
  }
}

void sol(void){
  map<int, int>::iterator ite;
  for(ite = ma.begin(); ite != ma.end(); ite++){
    while(ite->second){
      M = ite->first / 3 * 4;
      ma[M]--;
      ans.push_back(ite->first);
      ite->second--;
    }
  }
}

int main(void){
  int i, j;
  scanf("%d", &T);
  for(i = 1; i <= T; i++){

    ini();

    sol();
    
    printf("Case #%d: ", i);
    for(j = 0; j < ans.size(); j++){
      printf("%d", ans[j]);
      if(j == ans.size() - 1) printf("\n");
      else printf(" ");
    }
    ans.clear();
  }
}
