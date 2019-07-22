#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, Q;
int Mo[10], Sh[10];
char Mstr[1005], Sstr[1005];
void ini(void){
  scanf("%d", &N);
  scanf("%s%s", Sstr, Mstr);
}

void GG( void ){
  memset(Mo, 0, sizeof(Mo));
  memset(Sh, 0, sizeof(Sh));
  for(int i = 0; i < N; ++i){
    ++Mo[ Mstr[i] - '0' ];
    ++Sh[ Sstr[i] - '0' ];
  }
}

void sol(void){
  GG();
  for(int i = 0, j; i < 10; ++i){
    j =  min(Mo[i], Sh[i]);
    Mo[i] -= j;
    Sh[i] -= j;
  }
  for(int i = 0, j = 1; i < 10; ++i){
    for(; Sh[i] && j < 10;){
      if(i < j && Mo[j]){
        int x = min(Mo[j], Sh[i]);
        Mo[j] -= x;
        Sh[i] -= x;
      }else ++j;
    }
  }
  int ans = 0;
  for(int i = 0; i < 10; ++i) ans += Mo[i];
  printf("%d\n", ans);
  GG();
  for(int i = ans = 0, j = 1; i < 10; ++i){
    for(; Sh[i] && j < 10;){
      if(i < j && Mo[j]){
        int x = min(Mo[j], Sh[i]);
        Mo[j] -= x;
        Sh[i] -= x;
        ans += x;
      }else ++j;
    }
  }
  printf("%d\n", ans);
}

int main(void){
  int i, j;

  ini();

  sol();

}
