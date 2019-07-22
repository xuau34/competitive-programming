#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
vector<pair<int, int> > arr[4];
vector< vector< pair<int, int> > > ans;
vector<int> dis;
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      scanf("%d", &Q);
      if(Q) arr[Q].push_back( make_pair(i, j) );
    }
  }
}

void sol(void){
  int I, J, K, temp;
  for(int i = 0, ii = arr[1].size(); i < ii; ++i){
    for(int j = 0, jj = arr[2].size(); j < jj; ++j){
      for(int k = 0, kk = arr[3].size(); k < kk; ++k){
      }
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
