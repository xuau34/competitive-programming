#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, Q, arr[6] = {1, 2, 3, 4, 6, 12};
bool che[20];
void ini(void){
  scanf("%d", &N);
}

void sol(void){
  char str[15];
  while(N--){
    memset(che, 0, sizeof(che));
    scanf("%s", str);
    for(int i = 0, f; i < 6; ++i){
      if(che[arr[i]]) continue;
      f = 0;
      for(int j = arr[i] - 1; j < 12; j += arr[i]){
        if(str[j] != 'X'){
          f = 1;
          break;
        }
      }
      if(f){
        for(int j = 0, w; j < arr[i] - 1; ++j){
          w = 0;
          for(int k = j; k < 12; k += arr[i]){
            if(str[k] != 'X'){
              w = 1;
              break;
            }
          }
          if(!w){
            che[arr[i]] = 1;
            break;
          }
        } 
      }else{
        for(int j = i; j < 6; ++j) if(arr[j] % arr[i] == 0) che[arr[j]] = 1;
      }
    }
    int ans = 0;
    for(int i = 1; i < 13; ++i) if( che[i] ) ++ans;
    printf("%d", ans);
    for(int i = 12; i > 0; --i){
      if( che[i] ) printf(" %dx%d", 12 / i, i);
    }
    printf("\n");
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
