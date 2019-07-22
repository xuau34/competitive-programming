#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[100005];
int z[100005], ans[100005];

inline void Z(char *s){
  int len = N, l=0,r=0;
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
  Z(str);
}

void sol(void){
  vector<int> QQ;
  for(int i = 1; i <= N; ++i){
    if(z[N - i] == i) QQ.push_back(i);
    ++ans[ z[N - i] ];
  }
  for(int i = N; i; --i) ans[ i - 1 ] += ans[ i ];
  printf("%d\n", QQ.size());
  for(int i : QQ){
    printf("%d %d\n", i, ans[i]);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
