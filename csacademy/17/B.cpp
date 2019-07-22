#include <bits/stdc++.h>
using namespace std;
int T, N, R, B, red[100001], blue[100001];

void ini(void){
  scanf("%d%d%d", &N, &R, &B);
  for(int i = 0; i < R; ++i) scanf("%d", red + i);
  for(int i = 0; i < B; ++i) scanf("%d", blue + i);
  sort( red, red + R );
  sort( blue, blue + B );
}

void sol(void){
  int prev = -1;
  long long sum = 0;
  for(int i = 0; i < R; ++i){
    while( prev + 1 < B && blue[prev + 1] < red[i] ) ++prev;
    sum += min( (prev > -1)?red[i] - blue[prev]: INT_MAX, (prev + 1 < B)? blue[prev + 1] - red[i]: INT_MAX);
  }
  printf("%lld\n", sum);
}

int main(void){
  int i, j;

  ini();

  sol();

}
