#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
string a[1005], b[1005];
map<string, bool> A, B;
void ini(void){
  cin >> N >> M;
  for(int i = 0; i < N; ++i){
    cin >> a[i];
    A[a[i]] = 1;
  }
  for(int i = 0; i < M; ++i){
    cin >> b[i];
    if( A.find(b[i]) != A.end() ){
      ++Q;
    }
  }
  //printf("Q = %d\n", Q);
}

void sol(void){
  int i = 0, j = 0;
  N -= Q, M -= Q;
  for(; ;){
    if(Q) --Q;
    else{
      if(N == 0){
        printf("NO\n");
        return;
      }
      --N;
    }
    if(Q) --Q;
    else{
      if(M == 0){
        printf("YES\n");
        return;
      }
      --M;
    }
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
