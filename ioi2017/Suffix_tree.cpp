#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
int T, N, M, Q;
int n, k;
int sa1[MAXN], ra[MAXN], tmp[MAXN]; //sa -> 後綴數組 ra -> 排名數組

//排名數組倍增由前個排名數組可知
bool cmp_sa(int i, int j){
  if(ra[i] != ra[j]) return ra[i] < ra[j];
  i = (i + k > n)? -1: i + k;
  j = (j + k > n)? -1: j + k;
  return ra[i] < ra[j];
}

void build_sa(string x, int *sa){
  n = x.length();

  for(int i = 0; i <= n; i++){
    sa[i] = i;
    ra[i] = i < n ? x[i] : -1;
  }

  for(k = 1; k <= n; k<<=1){
    sort(sa, sa + n + 1, cmp_sa);

    tmp[sa[0]] = 0;
    for(int i = 1; i <= n; i++) tmp[sa[i]] = tmp[sa[i - 1]] + (cmp_sa(sa[i - 1], sa[i]) ? 1: 0);

    copy_n(tmp, n, ra);
  }
}
int main(void){
  int i, j;
  string str;
  cin>>str;
  build_sa(str, sa1);
}
