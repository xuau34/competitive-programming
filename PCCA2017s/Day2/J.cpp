#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  /***/
using namespace std;
const double eps = 1e-9;
int T, N, M, Q, pt[705][2], ans;
vector<double> v;
void ini(void){
  ans = 0;  /***/
  for(int i = 0; i < N; ++i) scanf("%d %d", pt[i], pt[i] + 1);
}

void sol(void){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(i == j) continue;
      v.push_back( fabs( ((double)pt[j][1] - pt[i][1]) / (pt[j][0] - pt[i][0]) ) ); /***/
    }
    sort( v.begin(), v.end() );
    double k = v[0];
    int sum = 1;
    for(int j = 1; j < v.size(); ++j){
      if( v[j] - k < eps ) ++sum;
      else{
        sum = 1;
        k = v[j];
      }
      ans = max(ans, sum + 1);
    }
    v.clear();
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  while( scanf("%d", &N) && N ){
    ini();
    sol();
  }
}
