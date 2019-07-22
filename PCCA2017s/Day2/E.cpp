#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[505], len[505], cost[505], sing[505];
bool cho[505];
void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", arr + i);
    len[i] = 1;
  }
  cost[0] = 1;
  for(int i = 1; i < N; ++i){
    double c, j;
    if(arr[i] == arr[i - 1]) c = i - 0.5, j = 0.5;
    else c = i, j = 0;
    for(; c - j - 1 >= 0 && c + j + 1 < N && arr[(int)(c - j - 1)] == arr[(int)(c + j + 1)]; ++j)
      ;//cho[(int)(c - j - 1)] = cho[(int)(c + j + 1)] = 1;
    if( arr[(int)(c - j)] == arr[(int)(c + j)] ){
      len[(int)(c - j)] = (j * 2) + 1;
      if((int)(c - j) != i)
        ;//cho[(int)(c - j)] = cho[(int)(c + j)] = 1;
    }else len[(int)(c - j)] = (j * 2);

    for(int k = c - j + 1; k <= c + j; ++k){
      cho[k] = 1;
    }
    //printf("i = %d => len[%d] = %d, cho: ", i, (int)(c - j), len[(int)(c - j)]);
    for(int k = 0;  k < N; ++k) printf("%d ", cho[k]);
    printf("\n");
  }
}

bool fail(int i, int j){
  for(int k = j + 1; k < i; k += len[k]) if(!sing[k]){
    //printf("%d,", k);
    return 1;
  }
  return 0;
}

void sol(void){
  int a;
  for(int i = 0; i < N; i += len[i]){
    cost[ (a = i) ] = ((i)?cost[ i - 1 ]: 0) + 1;
    for(int j = i - 1; j >= 0; --j){
      if( arr[i] != arr[j] || cho[j] || ( !cho[j] && len[j] > 1 && len[i] == 1 ) || fail(i, j) ) continue;
      cost[ i ] = min( cost[i], cost[i - 1] - cost[j] + ( (j - 1 >= 0)? cost[j - 1]: 0 ) );

      a = j;

      /*
      if( cost[ i - 1 ] - cost[ j ] > 1 ){
        if( sing[i] - sing[j] > 1 ){
          sing[i] -= 2;
        }else{
          --sing[i];
          ++cost[i];
        }
      }
      */
      //printf("sing = %d, j = %d ", sing[i], cost[i - 1] - cost[j], j);
      printf("%d ", j);
    }
    cost[ i + len[i] - 1 ] = cost[i];

    if(a == i){
      if( len[i] == 1) sing[i] = ( (i - 1 >= 0)? sing[i - 1]: 0) + 1;
      else sing[i] = sing[i - 1];
    }else{
      cho[i] = 1;
      len[a] = 2;
      if( cost[ i - 1 ] - cost[ a ] > 1 ){
        //printf("sing[%d] - sing[%d] = %d - %d = %d ", i - 1, a - 1, sing[i - 1], sing[a - 1], sing[i - 1] - sing[a - 1]);
        if( sing[i - 1] - sing[a - 1] > 1 ){
          sing[i] = sing[i - 1] - 2;
        }else{
          sing[i] = sing[i - 1] - 1;
          ++cost[i];
        }
      }else sing[i] = sing[i - 1];
    }

    for(int k = 1; k < len[i]; ++k){
      sing[i + k] = sing[i];
      //printf("sing[%d] = ", i + k);
    }
    

    printf("%d sing = %d cost[%d] = %d\n", arr[i], sing[i], i, cost[i]);
  }
  printf("%d\n", cost[ N - 1 ]);
}

int main(void){
  int i, j;

  ini();

  sol();

}
