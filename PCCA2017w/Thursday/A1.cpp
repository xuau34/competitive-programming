#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<pair<int, int> > node[10005];
int n, k, ans, sons[10005][10005], Bigson[10005];
int Son(int x, int p){  //記錄該子樹之節點數（含頂點）
  int i, sum;
  for(i = 0, sum = 1; i < node[x].size(); i++){
    if(sons[node[x][i].first] >= 0 && node[x][i].first != p){
      sons[x][node[x][i].first] = Son(node[x][i].first, x);
      sum += sons[x][i];
      printf("(%d, %d):%d ", x, node[x][i].first, sons[x][node[x][i].first]);
    }
  }
  return sum;
}
int Biggest_son(int x, int p, int tot){ //回傳最大(節點數)子樹最小者ith 一併紀錄該點之子樹的最大節點數
  int i, j, temp = x, s = 0, Max = 0, Max_;
  for(i = 0; i < node[x].size(); i++){
    if(sons[x][node[x][i].first] >= 0 && node[x][i].first != p){

      j = Biggest_son(node[x][i].first, x, tot);

      if(Bigson[j] < Bigson[temp] || temp == x) temp = j;
      s += sons[x][node[x][i].first];
      Max = (Max < sons[x][node[x][i].first])? sons[x][node[x][i].first]: Max;
    }
  }
  if(p >= 0 && ((tot - s - 1) < Bigson[temp] || temp == x)) temp = p;
  if(Max < tot - s - 1) Max = tot - s - 1;
  if(Max < Bigson[temp]) temp = x;

  Bigson[x] = Max;
  return temp;
}
void Dis(int x, int p, int d, vector<int> &Vv){  //記錄頂點至各點之距離
  Vv.push_back(d);
  for(int i = 0; i < node[x].size() && d + node[x][i].second <= k; i++)
    if(node[x][i].first != p) Dis(node[x][i].first, x, d + node[x][i].second, Vv);
}
int Cal(vector<int> &Vv){  //計算頂點對頂點之ans （v要由小至大）
  int i, ret = 0, j = Vv.size();
  for(i = 0; i < Vv.size(); i++){
    while(j > 0 && Vv[i] + Vv[j - 1] > k) j--;
    ret += j - ((j > i)? 1: 0);
  }
  return ret / 2;
}
int Solve(int x, int p){
  int i, X, temp;
  vector<int> V;
  V.push_back(0); //很重要，為頂點對頂點之縮減版

  //temp = Son(x, p); //找出最小之最大子樹
  X = Biggest_son(x, p, temp);

  sons[p][X] = -1; //另一種visit
  for(i = 0; i < node[X].size(); i++) //處理子樹內的ans
    if(sons[node[X][i].first] >= 0 && node[X][i].first != p) Solve(node[X][i].first, X);

  for(i = 0; i < node[X].size(); i++){  //處理經過s的ans
    if(node[X][i].first != p){
      vector<int> v;
      Dis(node[X][i].first, X, node[X][i].second, v);
      sort(v.begin(), v.end());
      ans -= Cal(v);
      V.insert(V.end(), v.begin(), v.end());
    }
  }
  sort(V.begin(), V.end());
  ans += Cal(V);
  return ans;
}
int main(void){
  int i, x, y, z;
  while(~scanf("%d %d", &n, &k) && (n + k)){
    memset(sons, 0, sizeof(sons));
    memset(Bigson, 0, sizeof(Bigson));
    for(i = 1, ans = 0; i < n; i++){
      scanf("%d %d %d", &x, &y, &z);
      node[x].push_back(make_pair(y, z) );
      node[y].push_back(make_pair(x, z) );
    }
    Son(1, -1);
    cout<<Solve(1, -1)<<endl;
    for(i = 1; i <= n; i++) node[i].clear();
  }
}
