#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, z[2][200005], pre[2][200005];
char X[200005], Y[200005], A[200005], B[200005], Ar[200005];
inline void z_alg(char *s,int len,int *z){
  int l=0,r=0;
  z[0]=len;
  for(int i=1;i<len;++i){
    z[i]=i>r?0:(i-l+z[i-l]<z[l]?z[i-l]:r-i+1);
    while(i+z[i]<len&&s[i+z[i]]==s[z[i]])++z[i];
    if(i+z[i]-1>r)r=i+z[i]-1,l=i;
  }
}

void ini(void){
  scanf("%s", A);
  M = strlen(A);
  strcpy(Ar, A);
  reverse(Ar, Ar + M);
  scanf("%d", &N);
}

void sol(void){
  int ans = 0;
  while(N--){
    scanf("%s", B);
    Q = strlen(B);
    if(Q == 1 || Q > M) continue;
    strcpy(X, B); strcat(X, "@"); strcat(X, A);
    reverse(B, B + Q);
    strcpy(Y, B); strcat(Y, "@"); strcat(Y, Ar);
    T = Q + M + 1;
    z_alg(X, T, z[0]); z_alg(Y, T, z[1]);
    pre[0][0] = z[0][0]; pre[1][0] = z[1][0];
    for(int i = 1; i < T; ++i) pre[0][i] = max(pre[0][i - 1], z[0][i]), pre[1][i] = max(pre[1][i - 1], z[1][i]);
    for(int i = 0, j, k; i < M; ++i){
      j = i + z[0][i + Q + 1];
      k = M - j - 1;
    }
    //cin >> Q;
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
