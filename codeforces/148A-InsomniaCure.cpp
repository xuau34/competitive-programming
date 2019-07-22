#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, ans;
bool arr[100005];
void fun(int a){
  int i = 0;
  while(i + a <= N){
     i += a;
     if(!arr[i]){
       arr[i] = 1;
       ans++;
     }
  }
}
int main(void){
  int i, j, a, b, c, d;
  ans = 0;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &N);
  fun(a);
  fun(b);
  fun(c);
  fun(d);
  printf("%d\n", ans);
}
