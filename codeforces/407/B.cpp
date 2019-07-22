#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, B, L;
map<int, bool> ma;
void ini(void){
  scanf("%d %d %d %d", &B, &Q, &L, &M);
  for(int i = 0; i < M; i++){
    scanf("%d", &N);
    ma[N] = 1;
  }
}

void sol(void){
  long long sum = 0, tmp = B;
  int i;
  for(i = 0; i < 500 && abs(tmp) <= L; i++){
    if(ma.find(tmp) == ma.end()) sum++;
    tmp *= Q;
  }
  if(sum > 30) printf("inf\n");
  else printf("%d\n", sum);
  return;


  if(Q == 1 || B == 0){ 
    if(ma.find(B) == ma.end()) printf("inf\n");
    else printf("0\n");
    return;
  }
  if(Q == 0){
    if(ma.find(B) == ma.end() && ma.find(0) == ma.end()) printf("inf\n");
    else if(ma.find(B) == ma.end()) printf("1\n");
    else printf("0\n");
    return;
  }
  if(abs(B) > L) printf("0\n");
  else{
    long long sum = 0, tmp = B;
    while(abs(tmp) <= L){
      if(ma.find(tmp) == ma.end()) sum++;
      tmp *= Q;
    }
    printf("%d\n", sum);
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
