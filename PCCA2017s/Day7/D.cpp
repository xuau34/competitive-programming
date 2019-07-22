#include <bits/stdc++.h>
using namespace std;
int T, N, Q, ans[1005];
pair<int, pair<int, int> > pii[1005];
bool way[1005];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d%d%d", &pii[i].first, &pii[i].second.first, &pii[i].second.second);
    way[i] = ( pii[i].second.first <= pii[i].second.second );
  }
}

void sol(void){
  //int X, Y;
  double X, Y, M;
  for(int i = 0; i < N; ++i){
    for(int j = i + 1; j < N; ++j){

      //將時間拉一致
      if( pii[i].first >= pii[j].first )  
        X = pii[i].second.first, Y = pii[j].second.first + (pii[i].first - pii[j].first) * ( (way[j])? 1: -1 );
      else if( pii[i].first < pii[j].first )
        X = pii[i].second.first + (pii[j].first - pii[i].first) * ( (way[i])? 1: -1 ), Y = pii[j].second.first;

      //他們以同樣速率之中間值
      M = (X + Y) / 2;

      //確認是否於他們的路徑中
      if( ( (way[i])? X <= M && M <= pii[i].second.second :  pii[i].second.second <= M && M <= X ) &&
          ( (way[j])? Y <= M && M <= pii[j].second.second :  pii[j].second.second <= M && M <= Y ) ){
        ++ans[i], ++ans[j];
      }

    }
  }
  for(int i = 0; i < N; ++i) printf("%d ", ans[i]);
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
