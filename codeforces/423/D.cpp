#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, X, Y;
queue<int> que;
vector< pair<int, int> > vii;
void ini(void){
  scanf("%d%d", &N, &M);
}

void sol(void){
  Q = 1, T = (N / M);
  --N;
  for(int i = 0; i < M; ++i){
    vii.push_back( make_pair(1, ++Q) );
    //printf("1 %d\n", ++Q);
    que.push(Q);
    --N;
  }
  if(M > 1) X = Y = 1;
  else X = 1;
  while(N){
    //printf("%d %d\n", que.front(), ++Q);
    for(int i = 0; i < M && N; ++i, --N){
      vii.push_back( make_pair( que.front(), ++Q) );
      que.push(Q);
      que.pop();
      if(i < 2){
        if(X > Y) ++Y;
        else ++X;
      }
    }
  }
  printf("%d\n", X + Y);
  for(pair<int, int> pii: vii) printf("%d %d\n", pii.first, pii.second);
}

int main(void){
  int i, j;

  ini();

  sol();

}
