#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
vector<int> arr[2];
int main(void){
  int i, j, ans;
  scanf("%d", &N);
  for(i = 1; i <= N; i++){
    scanf("%d", &j);
    arr[(j & 1)].push_back(i);
  }
  if(arr[0].size() == 1) printf("%d\n", arr[0][0]);
  else printf("%d\n", arr[1][0]);
}
