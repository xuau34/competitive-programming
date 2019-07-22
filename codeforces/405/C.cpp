#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, ans[55];
char str[10];
deque<int> deq;
void ini(void){
  scanf("%d %d", &N, &M);
}

void sol(void){
  int count;
  scanf("%s", str);
  if(str[0] == 'Y'){
    for(int i = 0; i < M; i++){
      deq.push_back(i);
      ans[i] = i;
    }
    count = M - 1;
  }else{
    deq.push_back(0);
    ans[0] = 0;
    for(int i = 0; i < M - 1; i++){
      deq.push_back(i);
      ans[i + 1] = i;
    }
    count = M - 2;
  }
  deq.pop_front();
  /*
  for(int i = 0; i < M; i++) cout<<ans[i]<<" ";
  cout<<endl;
  */
  for(int i = 1; i <= N - M; i++){
    scanf("%s", str);
    if(str[0] == 'Y'){
      deq.push_back(++count);
      ans[i + M - 1] = count;
    }else{
      deq.push_back(deq.front());
      ans[i + M - 1] = deq.front();
    }
    //printf("ans[%d] = %d\n", i + M - 1, ans[i + M - 1]);
    deq.pop_front();
  }
  for(int i = 0; i < N; i++){
    int j = 0;
    if(!ans[i]) str[0] = 'a', j = 1;
    while(ans[i]){
      str[j++] = 'a' + ans[i] % 26;
      ans[i] /= 26;
    }
    str[j] = '\0';
    str[0] -= 32;
    printf("%s ", str);
  }
  printf("\n");
}

int main(void){
  int i, j;
  ini();

  sol();

}
