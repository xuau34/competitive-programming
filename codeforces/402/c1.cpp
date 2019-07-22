#include <bits/stdc++.h>
using namespace std;
int T, N, K, Q;
bool visit[200005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >  > now, after;
void ini(void){
  int i, j;
  scanf("%d %d", &N, &K);
  for(i = 0; i < N; i++){
    scanf("%d", &j);
    now.push(make_pair(j, i) );
  }
  for(i = 0; i < N; i++){
    scanf("%d", &j);
    after.push(make_pair(j, i) );
  }
}

void sol(void){
  int ans = 0, af = 0;
  while(!now.empty()){
    if(af < (N - K)){
      //printf("now %d, %d vs after %d, %d => ", now.top().first, now.top().second, after.top().first, after.top().second);
      if(now.top().first < after.top().first){
        ans += now.top().first;
        visit[now.top().second] = 1;
        now.pop();
      }else{
        ans += after.top().first;
        visit[after.top().second] = 1;
        after.pop();
        af++;
      }
    }else{
      ans += now.top().first;
      visit[now.top().second] = 1;
      now.pop();
    }
    //printf("ans = %d, af = %d\n", ans, af);
    //printf("now.top().second = %d visit => %d\n", now.top().second , visit[now.top().second]);
    while(!now.empty() && visit[now.top().second]) now.pop();
    while(!after.empty() && visit[after.top().second]) after.pop();
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
