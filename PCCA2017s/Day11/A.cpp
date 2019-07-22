#include <bits/stdc++.h>
using namespace std;
int z[300005], N, M;
// z[i] : 從s[i]開始的與從s[0]開始的匹配長度
inline void z_alg(char *s,int len,int *z){
  int l=0,r=0;
  z[0]=len;
  for(int i=1;i<len;++i){
    z[i]=i>r?0:(i-l+z[i-l]<z[l]?z[i-l]:r-i+1);
    while(i+z[i]<len&&s[i+z[i]]==s[z[i]])++z[i];
    if(i+z[i]-1>r)r=i+z[i]-1,l=i;
  }
}

bool check(int l){
  //printf("%d: ", l);
  for(int i = 0; i < N; ){
    //printf("z[%d] = %d, ", i, z[i]);
    if(z[i] < l) return 0;
    else i += l;
  }
  for(int i = N + 1; i < N + M + 1; ){
    //printf("z[%d] = %d, ", i, z[i]);
    if(z[i] < l) return 0;
    else i += l;
  }
  //printf("!!!!!\n");
  return 1;
}
char A[100005], B[100005], c[300005];
int main(void){
  int ans = 0;
  scanf("%s%s", A, B);
  N = strlen(A), M = strlen(B);

  for(int i = 0; i < N; ++i) c[i] = A[i];
  c[N] = '@';
  for(int i = N + 1, j = 0; i < N + M + 1; ++i, ++j) c[i] = B[j];
  //printf("%s %s => %s: ", a, b, c);
  z_alg(c, N + M + 1, z);

  for(int i = 1; i <= N && i <= M; ++i){
    //printf("A[%d ] = %c, B[%d] = %c\n", i, A[i], i, B[i]);
    if(A[i - 1] != B[i - 1]) break;
    if( check(i) ){
      //printf("i = %d\n", i);
      ++ans;
    }
    //printf("\n");
  }

  printf("%d\n", ans);
}
