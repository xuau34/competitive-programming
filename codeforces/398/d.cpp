#include <bits/stdc++.h>
using namespace std;
int T, N, M, K, arr[10000005];
vector<int> ans;
void ini(void){
  int i, j;
  scanf("%d %d %d", &N, &M, &K);
  for(i = 0; i < N; i++){
    scanf("%d", &j);
    arr[j]++;
    if(arr[j] > K){
      printf("-1\n");
      exit(0);
    }
  }
  for(i = 1; i <= M; i++){
    scanf("%d", &j);
    if(arr[j] < K){
      ans.push_back(i);
      arr[j]++;
    }
  }
}

void sol(void){
  cout<<ans.size()<<endl;
  for(int v: ans){
    cout<<v<<" ";
  }
  cout<<endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
