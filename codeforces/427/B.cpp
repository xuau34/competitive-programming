#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long arr[10];
void ini(void){
  scanf("%d", &N);

}

int sol(void){
  char c;
  while(scanf("%c", &c) == 1){
    if(c < '0' || c > '9') continue;
    //cout << c <<endl;
    int x = c - '0';
    M += x;
    if(arr[x] < 1e9) ++arr[x];
    if(M >= N) return 0;
  }
  M = N - M;
  //cout << M << endl;
  for(int i = 0; i < 9; ++i){
    for(int j = 0; j < arr[i]; ++j){
      M -= 9 - i;
      ++Q;
      //cout << M << "," << Q << " ";
      if(M <= 0) return Q;
    }
  }
}

int main(void){
  int i, j;

  ini();

  printf("%d\n", sol());

}
