#include <math.h>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
const  int maxn = 10001;
const double eps = 1e-8;
inline double sgn(double x) {return fabs(x)<eps?0:(x>0?1:-1);}
struct Point{
  double x,y;
  bool flag;
  bool operator < (const Point &p) const {
    return sgn(x-p.x)<0 || sgn(x-p.x)==0 && sgn(y-p.y)<0; 
  }
  bool operator == (const Point& t) const {
    return sgn(x-t.x)==0 && sgn(y-t.y)==0;
  }
}Po[maxn],set[maxn];
struct Seg{Point s,e;}seg[110];
struct Line {  double a, b, c;};
inline double cross(Point a,Point b,Point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
bool dotOnSeg(Point p, Point s, Point e) {                
  if ( p == s || p == e )     return true;
  return sgn(cross(s,e,p))==0 && sgn((p.x-s.x)*(p.x-e.x))<=0 && sgn((p.y-s.y)*(p.y-e.y))<=0;
} 
Line Turn(Point s, Point e) {                                    
  Line ln;
  ln.a =s.y - e.y ;
  ln.b =e.x - s.x;
  ln.c =s.x*e.y - e.x*s.y;
  return ln;
}
bool Seg_Inst(Seg s1, Seg s2, Point &p) {
  Line l1=Turn(s1.s,s1.e),l2=Turn(s2.s,s2.e);    
  double d = l1.a*l2.b - l2.a*l1.b;
  if ( sgn(d) ==0 )     return false;
  p.x = (-l1.c*l2.b + l2.c*l1.b) / d;
  p.y = (-l1.a*l2.c + l2.a*l1.c) / d;
  return dotOnSeg(p,s1.s,s1.e) && dotOnSeg(p,s2.s,s2.e);
}
bool bin(Point p[],int n,Point x){
  int l=0,r=n-1,mid;
  while(l<=r){
    mid=(l+r)>>1;
    if(p[mid]==x) return true;
    if(p[mid]<x) l=mid+1;
    else r=mid-1;
  }
  return false;
}
int t,n,m,tot;
Point from,to;
void init(){
  int i,j,k;
  scanf("%d%d",&n,&m);
  scanf("%lf%lf%lf%lf",&from.x,&from.y,&to.x,&to.y);
  for(i=0;i<n;i++)
    scanf("%lf%lf%lf%lf",&seg[i].s.x,&seg[i].s.y,&seg[i].e.x,&seg[i].e.y);
  for(i=0;i<m;i++){
    scanf("%lf%lf",&Po[i].x,&Po[i].y);
    Po[i].flag=true;
  }
  sort(Po,Po+m);
  tot=0;set[tot++]=from;set[tot++]=to;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      Point tmp;
      if(Seg_Inst(seg[i],seg[j],tmp))    set[tot++]=tmp;
    }
  }
  sort(set,set+tot);
  for(i=j=0;i<tot;i++){    
    if(!bin(Po,m,set[i]))
      if(i==0||!(set[i]==set[i-1]))
        set[j++]=set[i];
  }
  tot=j;
  for(i=0;i<tot;i++)set[i].flag=false;
  for(i=0;i<m;i++){
    int cnt=0;
    for(j=0;j<n;j++)
      if(dotOnSeg(Po[i],seg[j].s,seg[j].e))    cnt++;
    if(cnt==1)  set[tot++]=Po[i];
  }
  sort(set,set+tot);
}
vector<int> edge[maxn];
vector<int> dot_set_onseg[maxn];
void build(){
  int i,j,k;
  for(i=0;i<=n;i++) dot_set_onseg[i].clear();
  for(i=0;i<=tot;i++) edge[i].clear();
  for(i=0;i<n;i++)
    for(j=0;j<tot;j++)
      if(dotOnSeg(set[j],seg[i].s,seg[i].e))
        dot_set_onseg[i].push_back(j);
  for(i=0;i<n;i++){
    int SIZE=dot_set_onseg[i].size();
    for(j=0;j<SIZE-1;j++){
      while(j<SIZE-1&&set[dot_set_onseg[i][j]].flag) j++;
      if(j==SIZE-1) break;
      if(!set[dot_set_onseg[i][j+1]].flag){
        int a=dot_set_onseg[i][j];
        int b=dot_set_onseg[i][j+1];
        edge[a].push_back(b);
        edge[b].push_back(a);
      }
    }
  }
}
int vis[maxn];
bool bfs(){
  memset(vis,0,sizeof(vis));
  int st=lower_bound(set,set+tot,from)-set;
  int ed=lower_bound(set,set+tot,to)-set;
  queue<int> Q;
  Q.push(st);vis[st]=1;
  while(!Q.empty()){
    int fr=Q.front();Q.pop();
    for(int i=0;i<edge[fr].size();i++){
      if(vis[edge[fr][i]]) continue;
      if(edge[fr][i]==ed) return true;
      Q.push(edge[fr][i]);
      vis[edge[fr][i]]=1;
    }
  }
  return false;
}
int main(){
  scanf("%d",&t);
  while(t--){
    init();
    build();
    if(bfs()) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

