#include <bits/stdc++.h>
using namespace std;
int main(void){
  long long ans = 100000000000;
  printf("%d\n", ans);
  map<int, int> m;
  int i, j;
  m[1] = 2;
  m[2] = 3;
  m[3] = 4;
  for(auto &p : m){
    scanf("%d %d", &i, &j);
    m[i] = j;
    for(auto &pp : m){
      printf("(%d,%d) ", pp.first, pp.second);
    }
    printf("=> (%d, %d)\n", p.first, p.second);
  }
}
