#include <bits/stdc++.h>
using namespace std;
int N, K, arr[100005], ans;
long long T, Q;
multimap <long long, bool> m;
void ini(void){
  int i;
  scanf("%d %d", &N, &K);
  for(i = T = Q = ans = 0; i < N; i++){
    scanf("%d", arr + i);
    if(arr[i] > 0) T += arr[i];
    else Q += arr[i];
  }
  if(!K) m[K] = 1;
  else for(i = K; i <= T && i >= Q; i*=K) m[i] = 1;
}

multimap<long long, bool> sol(int l, int r){
  if(l + 1 == r){
    if(m.find(arr[l]) != m.end()) ans++;
    return arr[l];
  }
  int m = (l + r)/2, i;
  multimap<long long, bool> R = sol(m, r), L = sol(l, m);
  multimap<long long, bool>::iterator ite1, ite2;
  for(i = m - 1; i; i--){
    multimap<long long, bool> tmp;
    for(ite = m.begin(); ite != m.end(); ite++){
      if(ti.find(ite->first - arr[i]) != ti.end()) ans++;
    }
    for(ite = ti.begin(); ite != ti.end(); ite++){
      tmp[ite->first + arr[i]] = 1;
    }
    ti = tmp;
  }
  return ti;
}

int main(void){
  int i, j;

  ini();

  sol();

}
