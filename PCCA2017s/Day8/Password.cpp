#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, z[1000005], cnt[1000005];
char str[1000005];
vector<int> candy;
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
  scanf("%s", str);
  N = strlen(str);
  z_alg(str, N, z);
}

void sol(void){
  for(int i = 1; i < N; ++i){
    ++cnt[ z[i] ];
    if( z[i] == N - i ) candy.push_back( z[i] );
  }
  for(int i = N; i; --i) cnt[i - 1] += cnt[i];
  for(int i = 0, j = candy.size(); i < j; ++i){
    if(cnt[ candy[i] ] > 1){
      str[candy[i]] = 0;
      printf("%s\n", str);
      return;
    }
  }
  printf("Just a legend\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
