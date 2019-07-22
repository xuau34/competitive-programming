#include <cstdio>
#include <string.h>
#include <string>
#define NMAX 257
bool path[NMAX][NMAX],v[NMAX];
int n,mmax;
int dp[NMAX],seq[NMAX],seq_pos;
bool dfs(int pos,int size){       // 正在拜訪, 包含目前已經拜訪多少
  int i,j,unvis;
  bool tv[NMAX];
  unvis=0;              // 該探索而未探索
  for(i=pos; i<n; i++)    // 只考慮大於目前點
    if(!v[i]) unvis++;
  if(unvis==0) {
    if(size>mmax) {
      mmax=size;
      seq_pos=0;
      seq[seq_pos++]=pos+1;
      return true;    // 回傳有無更新答案
    }
    return false;
  }
  for(i=pos; i<n&&unvis>0; i++)
    if(!v[i]) {
      if(unvis+size<=mmax||dp[i]+size<=mmax) return false;
      v[i]=true;
      unvis--;
      memcpy(tv,v,sizeof(v));
      for(j=0; j<n; j++)
        if(!path[i][j]) v[j]=true;
      if(dfs(i,size+1)) {
        seq[seq_pos++]=pos+1;
        return true;
      }
      memcpy(v,tv,sizeof(v));
    }
  return false;
}
int max_clique(){
  int i,j;
  mmax=0;
  for(i=0; i<n; i++)
    path[i][i]=false;
  for(i=n-1; i>=0; i--) {       // 枚舉每個點
    for(j=0; j<n; j++)
      v[j]=!path[i][j];         // 初始化所有與原點不相鄰的點為已拜訪
    dfs(i,1);
    dp[i]=mmax;
  }
  return mmax;
}
int main(){
  int i,j,x,y,e,m,tn;
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d",&n,&e)==2&&n;
    memset(path,1,sizeof(path));          
    for(i=0; i<e; i++) {
      scanf("%d%d",&x,&y);x--;y--;
      path[x][y]=path[y][x]=false;     // 0-base 建邊
    }
    memset(dp,0,sizeof(dp));
    printf("%d\n",max_clique());
    for(i=0; i<seq_pos; i++){
      printf("%d",seq[i]);
      if( i != seq_pos - 1) printf(" ");
    }
    puts("");
  }
}
