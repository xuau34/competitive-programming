#include <bits/stdc++.h>
using namespace std;
int C = 0;
inline bool cmp(int &A, int &B){
  return abs(C - A) < abs(C - B);
}
int main(void){
  priority_queue<int, vector<int>, function< bool(int&, int&) > > que(cmp);
  for(int i = 1; i < 6; ++i) que.push(i);
  while( scanf("%d", &C) == 1 ){
    printf("%d\n", que.top() );
  }
}
