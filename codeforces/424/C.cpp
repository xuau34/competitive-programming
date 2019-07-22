#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[2005], ar[2005];
bool cnt[17000005], temp[17000005];
map<int, bool> m/*, cnt, temp*/;
void ini(void){
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; ++i) scanf("%d", arr + i);
  for(int i = 0; i < M; ++i){
    scanf("%d", ar + i);
    cnt[ar[i] + 8000000] = 1;
  }
}

void sol(void){
  int x, y;
  for(int i = 0; i < M; ++i){
    for(int j = 1; j <= N; ++j){
      //temp.clear();
      //memset(temp, 0, sizeof(temp));
      memcpy(temp, cnt, sizeof(cnt) );
      Q = 0, x = 1, temp[ar[i] + 8000000] = 0;
      for(int k = j - 1; k >= 0; --k){
        y = ar[i] - (Q += arr[k]) + 8000000; 
        //printf("(%d, %d) = %d\n", i, k, y);
        if( k && temp[ y ]){
          temp[ y ] = 0;
          ++x;
        }
      }
      T = ar[i] - Q;
      //printf("%d\n", x);
      Q = 0;
      for(int k = j; k < N; ++k){
        y = ar[i] + ( Q += arr[k] ) + 8000000;
        //printf("(%d, %d) = %d\n", i, k, y);
        if( temp[ y ] ){
          temp[ y ] = 1;
          ++x;
        }
      }
      if(x == M) m[T] = 1;
      //printf(" => %d, %d\n\n", x, m.size());
    }
  }
  printf("%d\n", m.size());
}

int main(void){
  int i, j;

  ini();

  sol();

}
