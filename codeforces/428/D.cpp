#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, cnt[1000005];
long long ans[1000005], pow2[200005];
const int mod = 1e9+7;
void ini(void){
  pow2[0] = 1;
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", &Q);
    M = max(M, Q);
    ++cnt[Q];
    pow2[i + 1] = (pow2[i] << 1);
    if(pow2[i + 1] > mod) pow2[i + 1] -= mod;   //為什麼不是>=??
  }
  //for(int i = 0; i <= M; ++i) printf("%d ", cnt[i]);
  //cout << endl;
}

void sol(void){
  long long a = 0;
  for(int i = M; i > 1; --i){
    int sum = 0;
    for(int j = i; j <= M; j += i) sum += cnt[j]; //改成在這裡加上去就過了OAO"
    if(!sum) continue;
    //printf("i = %d, sum = %d\n", i, sum);
    ans[i] = sum * pow2[ sum - 1 ] % mod;
    for(int j = i << 1; j <= M; j += i) ans[i] = (ans[i] + mod - ans[j]) % mod;
    a = (a + ans[i] * i) % mod;
  }
  printf("%lld\n", a);
}

int main(void){
  int i, j;

  ini();

  sol();

}
