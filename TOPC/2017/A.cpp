#include <bits/stdc++.h>
using namespace std;
int T, N, M, A, B;
bool a[10], b[10];

void ini(void){
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  scanf("%d%d", &N, &M);
  for(int i = 0, j; i < N; ++i) scanf("%d", &j), a[j] = 1;
  for(int i = 0, j; i < M; ++i) scanf("%d", &j), b[j] = 1;
  

}

void sol(void){
  for(int i = A = B = 0; i < 10; ++i){
    if(a[i] && b[i]) ++A;
    if(a[i] || b[i]) ++B;
  }
  if(A << 1 > B) printf("1\n");
  else printf("0\n");
}

int main(void){
  scanf("%d", &T);
  while(T--){
    ini();

    sol();
  }
}
