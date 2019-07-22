#include <bits/stdc++.h>
using namespace std;
int arr[105][105], n, m, k, x, y, N, S, M, Min;
void Flow(int X, int Y, int K, int w){
  arr[X][Y]++;
  if(K > 1){
    if(w){
      if(Y == m){
        if(X == 1) Flow(2, 1, K - 1, 0);
        else Flow(X - 1, 1, K - 1, 1);
      }else Flow(X, Y + 1, K - 1, 1);
    }else{
      if(Y == m){
        if(X == n) Flow(n - 1, 1, K - 1, 1);
        else Flow(X + 1, 1, K - 1, 0);
      }else Flow(X, Y + 1, K - 1, 0);
    }
  }
}
int main(void){
  scanf("%d %d %d %d %d", &n, &m, &k, &x, &y);
  S = n * m;
  N = (k - 5 * S) / (9 * S);
  M = (k - 5 * S) % (9 * S);
  cout<<S<<","<<N<<","<<M<<endl;
  Min = N + 1;
  Flow(n - 1, 1, M, 1);
  printf("%d %d %d\n", Min, N * 2 + 1, Min + arr[x][y]);
}
