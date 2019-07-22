#include <stdio.h>
int main(void){
  int i, N, times = 1;
  char c, keep;
  scanf("%d\n", &N);
  scanf("%c", &keep);
  for(i = 1; i < N; i++){
    scanf("%c", &c);
    if(c != keep){
      if((keep == 'e' || keep == 'o') && times == 2) printf("%c%c", keep, keep);
      else if(keep == 'a' || keep == 'e' || keep == 'i' || keep == 'o' || keep == 'u' || keep == 'y')
        printf("%c", keep);
      else{
        while(times--) printf("%c", keep);
      }
      keep = c;
      times = 1;
    }else times++;
  }
  if((keep == 'e' || keep == 'o') && times == 2) printf("%c%c\n", keep, keep);
  else if(keep == 'a' || keep == 'e' || keep == 'i' || keep == 'o' || keep == 'u' || keep == 'y')
    printf("%c\n", keep);
  else{
    while(times--) printf("%c", keep);
    printf("\n");
  }
}
