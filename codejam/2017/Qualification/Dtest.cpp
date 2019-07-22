#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[10][10], ans[10][10], sum;
bool visit[10][10];
void ini(void){
  cin>>N;
}

void Fill(int x, int y, int X){
  int i, j;
  //printf(" Fill(%d, %d, %d):\n", x, y, X);
  if(X & 2){
    for(i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) if(!visit[i][j]) arr[i][j] &= 1;
    for(i = x + 1, j = y + 1; i < N && j < N; i++, j++) if(!visit[i][j]) arr[i][j] &= 1;
    for(i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++) if(!visit[i][j]) arr[i][j] &= 1;
    for(i = x + 1, j = y - 1; i < N && j >= 0; i++, j--) if(!visit[i][j]) arr[i][j] &= 1;
  }
  if(X & 1){
    for(i = x, j = 0; j < N; j++)
      if(!visit[i][j]) arr[i][j] &= 2;
    for(i = 0, j = y; i < N; i++)
      if(!visit[i][j]) arr[i][j] &= 2;
  }
  /*
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++) cout<<arr[i][j]<<" ";
    cout<<endl;
  }
  */
}

void sol(int x, int y){
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) arr[i][j] = 3;
  memset(visit, 0, sizeof(visit));
  visit[x][y] = 1;
  Fill(x, y, 3);
  int temp = 0;
  printf("From (%d, %d):\n", x, y);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      visit[i][j] = 1;
      Fill(i, j, arr[i][j]);
      if(arr[i][j] > 1) temp += (arr[i][j] - 1);
      else if(arr[i][j]) temp += 1;
      cout<<arr[i][j]<<" ";
      /*
      int lo = 0;
      cin>>lo;
      lo++;
      */
    }
    cout<<endl;
  }
  printf("sum = %d\n", temp);
  cout<<endl;
  if(temp > sum){
    sum = temp;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++) ans[i][j] = arr[i][j];
    }
  }
}

int main(void){
  int i, j;

  ini();
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++) sol(i, j);
  }
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++) cout<<ans[i][j]<<" ";
    cout<<endl;
  }
}
