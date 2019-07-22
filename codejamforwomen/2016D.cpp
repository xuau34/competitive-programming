#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char str[30];
bool vi[30];
vector<char> arr[30];
void ini(void){
  int i, j;
  scanf("%d", &N);
  while(N--){
    scanf("%s", str);
    j = strlen(str);
    if(j == 1){
      Q = 1;
      return;
    }
    for(i = 0, --j; i < j; i++){
      arr[str[i] - 'A'].push_back(str[i + 1]);
    }
  }
}

void sol(void){
  memset(vi, 0, sizeof(vi));
  int I = 0;
  for(int i = 0; i < 26; i++){
    for(int j = arr[i].size() - 1; j >= 0; j--){
      if(arr[i][j] != i + 'A' && vi[arr[i][j] - 'A']) continue;
      vi[arr[i][j] - 'A'] = 1;
      str[I++] = arr[i][j];
    }
    if(!vi[i]){
      vi[i] = 1;
      str[I++] = i + 'A';
    }
    //printf("i = %d: %s\n", i, str);
    arr[i].clear();
  }
}

int main(void){
  int i, j;
  scanf("%d", &T);
  for(i = 1; i <= T; i++){
    printf("Case #%d: ", i);
    ini();

    if(Q){
      Q = 0;
      printf("IMPOSSIBLE\n");
      continue;
    }
    sol();
    for(j = 0; j < 26; j++) printf("%c", str[j]);
    printf("\n");

  }
}
