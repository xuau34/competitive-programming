#include <stdio.h>
#include <stdlib.h>

void _swap( void *a, void *b ){
 void *ptr = a;
 a = b;
 b = ptr;
}

int main(void){
  int a = 2, b = 3;
  _swap( &a, &b );
  printf("a = %d, b = %d\n", a, b);
}
