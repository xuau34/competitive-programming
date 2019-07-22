//hi~ :)
#include <bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define fastio ios::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
bool _cmp(const pair<int,int>&i, const pair<int,int>&j){
  return ((i.first == j.first) ? (i.second>j.second) : (i.first<j.first));
} //x increase, y decrease
struct Node{
  int x, y;
  Node(int a=0, int b=0):
    x(a), y(b){}
  bool operator < (const Node& a)const{
    return ((x==a.x) ? (y>a.y) : (x<a.x));
  }//x increase, y decrease
};

const int mxn = 1e0 + 1;
double eps = 1e-9;
ll ncase = 1;
ll N,M,a,b,c,K;
string str;
int arr[1005];
pii rec[1005];

void pre(){
  return;
}
void init(){
  N = getint();
  K = getint();
  memset(arr, 0, sizeof(arr));
//  memset(rec, 0, sizeof(rec));
  arr[0] = arr[N+1] = N+1;
}
pii cal(int x){
  int l,r;
  for(int i=0;x-i-1>=0;i++)
    if(arr[x-i-1]>0){
      l = i;
      break;
    }
  for(int i=0;x+i+1<=N+1;i++)
    if(arr[x+i+1]>0){
      r = i;
      break;
    }
  return MP(min(l,r), max(l,r));
}
void sol(){
  for(int ii=1;ii<=K;ii++){
    a = -1;
    for(int i=1;i<=N;i++){
      if(arr[i] > 0) continue;
      if(a == -1) a = i;
      if(cal(a) < cal(i)) a = i;  // {min(R,L), max(R,L)}
    }
    /*
    int sum = 0;
    map<long long, int> m;
    for(int i = 1; i <= N; i++){
      if(arr[i] > 0){
        m[sum]++;
        sum = 0;
      }else sum++;
    }
    m[sum]++;
    for(auto i: m) printf("(%lld, %d) ", i.first, i.second);
    cout<<endl;
    */
    arr[a] = ii;
//    rec[a] = cal(a);
  }

  /*
  for(int i=1;i<=N;i++) cout << setfill('0') << setw(4) << arr[i] << " ";
  cout << endl;
  for(int i=1;i<=N;i++) cout << setfill('0') << setw(2) << rec[i].X << setw(2)<< rec[i].Y << " ";
  cout << endl;
  */

  return ;
}

int main(){
  pre();
  ncase = getint();
  for(int I=1;I<=ncase;I++){
    init();
    sol();
    auto ii = cal(a);
    cout << "Case #" << I << ": " << ii.Y << " " << ii.X << endl;
  }
}
