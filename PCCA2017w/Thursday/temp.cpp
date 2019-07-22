#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 10005
struct Edge
{
      int v,w;
          Edge(int vi, int wi) :v(vi), w(wi){}
              Edge(){}
                  bool operator <(const Edge &y)const
                        {
                                  return w<y.w;
                                      }
};
vector<Edge>E[maxn];
int n,k;
int f[maxn];
int sum,root,ans,cnt;
int vis[maxn],son[maxn],d[maxn],deep[maxn];
void init()
{
      root = ans = cnt = 0;
          for(int i=0;i<=n;i++)
                    E[i].clear();
              memset(f,0,sizeof(f));
              memset(vis,0,sizeof(vis));
              memset(son,0,sizeof(son));
              memset(d,0,sizeof(d));
              memset(deep,0,sizeof(deep));
}
void getroot(int x,int fa)
{
      son[x]=1;f[x]=0;
          for(int i=0;i<E[x].size();i++)
                {
                    int v = E[x][i].v,w = E[x][i].w;
                    if(v == fa || vis[v])continue;
                    getroot(v,x);
                    son[x]+=son[v];
                    f[x]=max(f[x],son[v]);
                }
              f[x]=max(f[x],sum-son[x]);
                  if(f[x]<f[root])root=x;
}
void getdeep(int x,int fa)
{
      deep[++deep[0]]=d[x];
          for(int i=0;i<E[x].size();i++)
                {
                          int v = E[x][i].v,w = E[x][i].w;
                                  if(v == fa || vis[v])continue;
                                          d[v]=d[x]+w;
                                                  getdeep(v,x);
                                                      }
}
int cal(int x,int now)
{
      d[x]=now;deep[0]=0;
          getdeep(x,0);
              sort(deep+1,deep+deep[0]+1);
                  int t=0,l=1,r=deep[0];
                  printf("(%d, %d): %d", x, now, t);
                      while(l<r)
                            {
                                      if(deep[l]+deep[r]<=k)
                                                    t+=r-l,l++;
                                              else r--;
                                            printf(" -> %d", t);
                                                  }
                      cout<<endl;
                      for(int i = 1; i <= deep[0]; i++) cout<<deep[i]<<" ";
                      cout<<endl;
                          return t;
}
void solve(int x)
{
      ans += cal(x,0);
          vis[x]=1;
              for(int i=0;i<E[x].size();i++)
                    {
                              int v = E[x][i].v,w = E[x][i].w;
                                      if(vis[v])continue;
                                              ans -= cal(v,w);
                                                      sum = son[v];
                                                              root = 0;
                                                                      getroot(v,root);
                                                                              solve(root);
                                                                                  }
}
int main()
{
      while(scanf("%d%d",&n,&k)!=EOF)
            {
                      if(n==0&&k==0)break;
                              init();
                                      for(int i=1;i<n;i++)
                                                {
                                                              int x,y,z;
                                                                          scanf("%d%d%d",&x,&y,&z);
                                                                                      E[x].push_back(Edge(y,z));
                                                                                                  E[y].push_back(Edge(x,z));
                                                                                                          }
                                              sum=n,f[0]=999999;
                                                      getroot(1,0);
                                                              solve(root);
                                                                      printf("%d\n",ans);
                                                                          }
}
