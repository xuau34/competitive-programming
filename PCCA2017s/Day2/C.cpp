#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
priority_queue<int> q;
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &M);
    if( M & 1 ) q.push( M );
    else if( M > 0 ) Q += M;
  }
    //printf("%d => ", Q);
}

void sol(void){
  Q += q.top();
  q.pop();
  //printf("%d\n", Q);
  while( !q.empty() ){
    T = q.top();
    //printf("%d + ", q.top());
    q.pop();
    if( q.empty() ) break;
    T += q.top();
    //printf("%d = %d => ", q.top(), T);
    q.pop();
    //printf("Q = %d\n", Q);
    if( T > 0 ) Q += T;
    else break;
  }
  printf("%d\n", Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
