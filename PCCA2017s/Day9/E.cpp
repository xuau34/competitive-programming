#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005][2];
vector< pair<int, int> > vii;
void ini(void){
  for(int i = 1; i <= N; ++i) scanf("%d%d", arr[i], arr[i] + 1);
}

void sol(void){
  vii.push_back( make_pair(arr[0][1], arr[0][0]) );
  vii.push_back( make_pair(arr[1][1], arr[1][0]) );
  arr[1][1] = 1;
  long long x, a, b;
  for(int i = 2; i <= N; ++i){
    sort(vii.begin(), vii.end());
    x = lower_bound( vii.begin(), vii.end(), make_pair(arr[i][1], arr[i][0]) ) - vii.begin();
    /*
    printf("vii: ");
    for(pair<int, int> pii: vii){
      printf("(%d, %d) ", pii.first, pii.second);
    }
    */
    //printf("\ni = %d, x = %d, vii[%d] = (%d, %d), vii[%d] = (%d, %d)\n", i, x, x - 1, vii[x - 1].first, vii[x - 1].second, x, vii[x].first, vii[x].second);
    if(x - 1 >= 0) a = abs( arr[i][1] - vii[x - 1].first );
    else a = 2000000000;
    b = abs( arr[i][1] - vii[x].first );
    vii.push_back( make_pair(arr[i][1], arr[i][0]) );
    if(a < b || a == b) arr[i][1] = vii[x - 1].second;
    else arr[i][1] = vii[x].second;
  }
  for(int i = 1; i <= N; ++i) printf("%d %d\n", arr[i][0], arr[i][1]);
  vii.clear();
}

int main(void){
  int i, j;
  arr[0][0] = 1, arr[0][1] = 1000000000;
  while(scanf("%d", &N) && N){
    ini();
    sol();
  }
}
