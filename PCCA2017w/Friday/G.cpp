#include <bits/stdc++.h>
using namespace std;
int arr[1005], t, n, q, l, r;
int main(void){
  int i, j, ans;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
      scanf("%d", arr + i);
    scanf("%d", &q);
    for(i = 0; i < q; i++){
      scanf("%d %d", &l, &r);
      for(j = l, ans = 0; j <= r; j++) ans = (ans < arr[j])? arr[j]: ans;
      cout<<ans<<endl;
    }
  }
}
