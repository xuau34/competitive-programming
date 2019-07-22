#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, R, sum, arr[1000005];
vector<int> node[1000005];
vector<int> ans;

void ini(void){
  int i, j;
  sum = 0;
  scanf("%d", &N);
  for(i = 1; i <= N; i++){
    scanf("%d %d", &j, arr + i);
    sum += arr[i];
    if(j == 0) R = i;
    else node[j].push_back(i);
  }
}

int sol(int x){
  int s = arr[x];
  for(int v: node[x]){
    s += sol(v);
  }
  if(s == sum / 3){
    ans.push_back(x);
    if(ans.size() == 2){
      for(int v: ans){
        printf("%d ", v);
      }
      printf("\n");
      exit(0);
    }else return 0;
  }
  return s;
}

int main(void){
  int i, j;

  ini();
  if(!sum || sum % 3) printf("-1\n");
  else{

    sol(R);

    printf("-1\n");
  }

}
