#include <bits/stdc++.h>
using namespace std;
int F[20], sg[1005];
void initial(){
 for(int i = 3; i <= 15; i++)
  F[i] = F[i - 1] + F[i - 2];
}
int SG(int x){
  if(sg[x] != -1) return sg[x];
  int i, j;
  set<int> s;
  for(i = 1, j = 0; i <= 15; i++){
    if(F[i] <= x)
      s.insert(SG(x - F[i]));
  }
  while(s.count(j) != 0) j++;
  //cout<<"sg["<<x<<"]="<<j<<endl;
  return sg[x] = j;
}
int main(void){
  int m, n, p, ans;
  F[1] = 1; F[2] = 2;
  memset(sg, -1, sizeof(sg));
  initial();
  //for(int i = 0; i <= 15;i++) cout<<i<<","<<F[i]<<endl;
  sg[0] = 0;
  while(scanf("%d %d %d", &m, &n, &p) && (m + n + p) > 0){
    //cout<<SG(m)<<" "<<SG(n)<<" "<<SG(p)<<endl;
    //cout<<(SG(m)^SG(n))<<endl;
    ans = SG(m)^SG(n)^SG(p);
    //printf("ans = %d\n",ans);
    if(ans) printf("Fibo\n");
    else printf("Nacci\n");
  }
}
