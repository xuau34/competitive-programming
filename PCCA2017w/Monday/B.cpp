#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int n, k;
int SG(int x){
  auto it = m.find(x);
  if(it != m.end()) return it->second;
  if(x & 1) return m[x] = 0;
  if(!(k & 1)) return m[x] = 1;
  int y = SG(x>>1);
  return m[x] = (y != 0)? y ^ 3: 1;
}
int main(void){
  scanf("%d %d", &n, &k);
  if(k & 1){
    m[0] = m[2] = 0;
    m[1] = m[3] = 1;
    m[4] = 2;
  }else{
    m[0] = m[3] = 0;
    m[1] = m[4] = 1;
    m[2] = 2;
  }
  int i, j, ans;
  //for(i = 0; i < 40; i++) cout<<SG(i)<<" ";
  for(i = 0; i < n; i++){
    scanf("%d", &j);
    if(i) ans ^= SG(j);
    else ans = SG(j);
  }
  if(ans) printf("Kevin\n");
  else printf("Nicky\n");
}
