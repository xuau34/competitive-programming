#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, L, R, arr[2][100005];
map<int, int> box[2];

void ini(void){
  scanf("%d %d %d", &N, &L, &R);
  for(int i = 1; i <= N; i++) scanf("%d", arr[0] + i);
  for(int i = 1; i <= N; i++) scanf("%d", arr[1] + i);
}

void sol(void){
  for(int i = 1; i <= N; i++){
    if( i >= L && i <= R){
      box[0][ arr[0][i] ]++;
      box[1][ arr[1][i] ]++;
    }else if( arr[0][i] != arr[1][i] ){
      printf("LIE\n");
      return;
    }
  }
  if(box[0].size() != box[1].size() ){
    printf("LIE\n");
    return;
  }
  auto i = box[0].begin();
  auto j = box[1].begin(); 
  for(; i != box[0].end(); i++, j++){
    //printf("(%d, %d) vs (%d, %d)\n", (*i).first, (*i).second, (*j).first, (*j).second);
    if((*i).second != (*j).second){
      printf("LIE\n");
      return;
    }
  }
  printf("TRUTH\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
