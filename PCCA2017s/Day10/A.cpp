#include <iostream>
#include <queue>
using namespace std;
int T, N, M, Q, arr[20005];
priority_queue<pair<int, pair<int, int> > > q;
void ini(void){
  int a, b, c;
  while(!q.empty()) q.pop();
  scanf("%d %d %d", &N, &M, &Q);
  while(Q--){
    scanf("%d %d %d", &a, &b, &c);
    q.push(make_pair(c, make_pair(a, b + N) ) );
  }
}

int par(int x){
  if(arr[x] != x) return arr[x] = par(arr[x]);
  else return x;
}

bool check(int a, int b){
  a = par(a);
  b = par(b);
  return (a != b);
}

void sol(void){
  int c, i, j;
  long long ans = 0, conn = 0;
  pair<int, int> p;
  for(int i = 0; i < N + M; i++) arr[i] = i;
  while(!q.empty() && conn < N + M){

    //printf("q = (%d, (%d, %d))\n", q.top().first, q.top().second.first, q.top().second.second);
    c = q.top().first;
    p = q.top().second;
    q.pop();
    //printf("(%d, (%d, %d)): (%d, %d) => ", c, p.first, p.second, arr[p.first], arr[p.second]);
    if(check(arr[p.first], arr[p.second])){
      ans += c;
      conn++;
      i = p.second;
      while(arr[i] != i){
        j = arr[i];
        arr[i] = p.first;
        i = j;
      }
      arr[i] = p.first;
    }
    //printf("(%d, %d)\n", arr[p.first], arr[p.second]);
  }
  printf("%lld", ((long long)N + M) * 10000 - ans);
}

int main(void){
  int i = 0, j;
  scanf("%d", &T);
  while(T--){
    if(i) printf("\n");
    ini();
    sol();
    i = 1;
  }
}
