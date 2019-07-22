#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[2000005], z[2000005];

// z[i] : 從s[i]開始的與從s[0]開始的匹配長度
inline void z_alg(int *s,int len,int *z){
  int l=0,r=0;
  z[0]=len;
  for(int i=1;i<len;++i){
    z[i]=i>r?0:(i-l+z[i-l]<z[l]?z[i-l]:r-i+1);
    while(i+z[i]<len&&s[i+z[i]]==s[z[i]])++z[i];
    if(i+z[i]-1>r)r=i+z[i]-1,l=i;
  }
}

void ini(void){
  scanf("%d%d", &N, &M);
  arr[M] = 2147483640;
  for(int i = 1; i <= N; ++i) scanf("%d", arr + i + M);
  for(int i = 0; i < M; ++i) scanf("%d", arr + i);
  z_alg( arr, N + M + 1, z);
  //for(int i = 0; i < N + M + 1; ++i) printf("%d ", z[i]);
  //printf("\n");
  for(int i = 1; i <= N; ++i){
    if( z[i + M] == M ){
      printf("%d\n", i);
      return;
    }
  }
  printf("-1\n");
}

void sol(void){

}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    ini();
    sol();
  }
}
