#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, now[200005], after[200005];
pair<int, int> pii[200005];
void ini(void){
  int i, j = 0;
  scanf("%d %d", &N, &M);
  for(i = 0; i < N; i++){
    scanf("%d", now + i);
  }
  for(i = 0; i < N; i++){
    scanf("%d", after + i);
    if(now[i] - after[i] > 0){
      pii[j++] = make_pair(now[i]-after[i], i);
    }
  }
  T = j;
}

void sol(void){
  int i, j;
  sort(pii, pii + T, greater<pair<int, int> >());
  for(i = 0; i < N - M && i < T; i++){
    j = pii[i].second;
    now[j] = after[j];
  }
  for(i = j = 0; i < N; i++){
    j += now[i];
  }
  printf("%d\n", j);
}

int main(void){
  int i, j;

  ini();

  sol();

}
