#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[100005], pos[100005], len[100005];

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", arr + i);
    pos[arr[i]] = i;
    len[i + 1] = 1;
  }
}

void sol(void){
  int mlen = 1;
  for(int i = 0, num; i < N; ++i){
    num = arr[i];
    if(num - 1 > 0 && pos[num - 1] < i ){
      pos[num] = pos[num - 1];
      if( ++len[ arr[pos[num]] ] > len[mlen] ) mlen = arr[ pos[num] ];
      //printf(" num - 1 = %d, len[ %d ] = %d\n", num - 1, arr[pos[num]], len[ arr[pos[num] ] ]);
    }
  }

  printf("%d\n", N - len[mlen]);
  for(int i = mlen - 1; i > 0; --i) printf("%d 0\n", i);
  for(int i = mlen + len[mlen]; i <= N; ++i) printf("%d 1\n", i);
}

int main(void){
  int i, j;

  ini();

  sol();

}
