#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int T, N, M, Q, arr[100005];

bool ini(void){
  bool ret = 1;
  scanf("%d", &N);
  memset(arr, 0, sizeof(arr));
  for(int x; N; --N){
    scanf("%d", &x);
    if(x > 100000) ret = 0;
    if(ret) ++arr[x];
  }
  /*
  for(int i = 0 ;i < 100005; ++i) if(arr[i]) printf("(%d, %d) ", i, arr[i]);
  printf("\n");
  */
  return ret;
}

bool sol(void){
  int x = 0;
  string str;
  while(1){
    if( arr[x + 1] ) --arr[ ++x ], str.push_back('W');
    else if( arr[x - 1] ) --arr[ --x ], str.push_back('L');
    else break;
  }
  for(int i = 0; i < 100005; ++i) if(arr[i]) return 0;
  if(x) return 0;
  cout << str << endl;
  return 1;
}

int main(void){
  scanf("%d", &T);

  for(int i = 1; i <= T; ++i){
    printf("Case %d: ", i);
    if( (!ini()) || (!sol()) ) printf("invalid\n");
  }
}
