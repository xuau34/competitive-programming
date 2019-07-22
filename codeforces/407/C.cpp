#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d", &N);
}

void sol(void){
  int pre, count = 0;
  long long sum = -100000000100000, ret = -100000000000000;
  scanf("%d", &pre);
  while(--N){
    scanf("%d", &M);
    if(count & 1 && (sum - abs(M - pre) < 0 || sum < abs(M - pre))){
      sum = -100000000100000;
      count = -1;
    }else{
      ret = max(sum, ret);
      if(sum < -100000000000000) sum = abs(M - pre);
      else sum = (count & 1)? sum - abs(M - pre): sum + abs(M - pre);
      count++;
    }
    printf("pre = %d vs %d : count = %d, sum = %lld, ret = %lld\n", pre, M, count - 1,sum, ret);
    pre = M;
  }
  printf("%lld\n", (ret < sum )? sum: ret);
}

int main(void){
  int i, j;

  ini();

  sol();

}
