#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
map<int, int> v, v1, v2;
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%d", &M), ++v[M];
  for(int i = 1; i < N; ++i) scanf("%d", &M), ++v1[M];
  for(int i = 2; i < N; ++i) scanf("%d", &M), ++v2[M];
}

void sol(void){
  for(pair<int, int> pii: v){
    if(pii.second > v1[pii.first]) M = pii.first;
    if(v1[pii.first] > v2[pii.first]) Q = pii.first;  //因可重複，所以不能單判一
  }
  printf("%d\n%d\n", M, Q);
}

int main(void){
  int i, j;

  ini();

  sol();

}
