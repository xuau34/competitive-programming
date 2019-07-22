#include <cstdio>
int main( void ){
  for(int i = 1; i <= 3; ++i){
    for(int j = 1; j <= 3; ++j){
      for(int k = 1; k <= 3; ++k){
        for(int l = 1; l <= 3; ++l){
          printf("(%d, %d, %d, %d)\n", i, j, k, l);
        }
      }
    }
  }
  /*
  printf("1\n500000\n");
  for(int i = 0; i < 500000; ++i) printf("%d ", i);
  printf("\n");
  for(int i = 1; i < 500000; ++i){
    printf("%d %d %d\n", i, i + 1, 0);
  }
  */
}
