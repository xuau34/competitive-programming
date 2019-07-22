#include <cstdio>
#include <cstring>
using namespace std;
int T, N, M, Q;

inline void z_alg(char *s,int len,int *z){
  int l=0,r=0;
  z[0]=len;
  for(int i=1;i<len;++i){
    z[i]=i>r?0:(i-l+z[i-l]<z[l]?z[i-l]:r-i+1);
    while(i+z[i]<len&&s[i+z[i]]==s[z[i]])++z[i];
    if(i+z[i]-1>r)r=i+z[i]-1,l=i;
  }
}

void sol(void){
  char a[105], b[105], c[205];
  scanf("%s%s", a, b);
  strcpy(c, b);
  strcat(c, a);
  printf("%s\n", c);
  int z[105];
  z_alg(c, strlen(c), z);
  for(int i = 0; i < strlen(c); ++i) printf("%d ", z[i]);
  printf("\n");

}

int main(void){
  int i, j;
  scanf("%d", &T);
  while(T--){
    sol();
  }
}
