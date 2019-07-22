#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long arr[10005], dp[15] = {7, 4, 1, 2, 8, 1, 4, 7, 2, 1, 8, 2};
map<long long, long long> visit, sg;
int main(void){
  long long i, j, v, k, kk, ans;
  scanf("%d", &T);

  for(i = 1; i <= 70; i++) sg[i] = visit[i] = 0;
  sg[0] = v = 0;
  for(i = 1ull; i <= 70; i++){
    v++;
    visit[sg[i - 1]] = v;
    for(j = 1; j < i - 2; j++) visit[sg[j] ^ sg[i - j - 1]] = v;
    visit[sg[i - 2]] = v;

    for(j = 1; j < i - 3; j++) visit[sg[j] ^ sg[i - j - 2]] = v;

    for(j = 1; j <= 70; j++){
      if(visit[j] != v){
        sg[i] = j;
        break;
      }
    }
  }
  /*
  for(i = 0; i <= 70; i++) cout<<sg[i]<<" ";
  cout<<endl;
  for(i = 71; i < 84; i++) cout<<dp[(i - 71) % 12]<<" ";
  cout<<endl;
  */

  while(T--){
    scanf("%d", &N);

    for(i = 0; i < N; i++){
      scanf("%lld", arr + i);
    }

    if(arr[0] > 70){ //printf("sg[%lld] = %lld\n", arr[i], dp[(arr[i] - 71) % 12]);
      ans = dp[(arr[0] - 71) % 12];
    }else ans = sg[arr[0]];

    for(i = 1; i < N; i++){
      if(arr[i] > 70){ //printf("sg[%lld] = %lld\n", arr[i], dp[(arr[i] - 71) % 12]);
        ans ^= dp[(arr[i] - 71) % 12];
      }else ans ^= sg[arr[i]];
    }

    if(ans) printf("F\n");
    else printf("S\n");
  }
}
