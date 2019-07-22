#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, ori[105][105], oriarr[105][105], arr[105][105], ans[105][105], sum, diff;
int visit[105][105];
void Fill(int x, int y, int X){
  int i, j;
  //printf(" Fill(%d, %d, %d):\n", x, y, X);
  if(X & 2){
    for(i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) if(!visit[i][j]) arr[i][j] &= 1;
    for(i = x + 1, j = y + 1; i < N && j < N; i++, j++)   if(!visit[i][j]) arr[i][j] &= 1;
    for(i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++)  if(!visit[i][j]) arr[i][j] &= 1;
    for(i = x + 1, j = y - 1; i < N && j >= 0; i++, j--)  if(!visit[i][j]) arr[i][j] &= 1;
  }
  if(X & 1){
    for(i = x, j = 0; j < N; j++) if(!visit[i][j]) arr[i][j] &= 2;
    for(i = 0, j = y; i < N; i++) if(!visit[i][j]) arr[i][j] &= 2;
  }
  /*
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++) cout<<arr[i][j]<<" ";
    cout<<endl;
  }
  */
}

void ini(void){
  cin>>N>>M;
  memset(ori, 0, sizeof(ori));
  memset(visit, 0, sizeof(visit));
  for(int i = sum = 0; i < N; i++) for(int j = 0; j < N; j++) arr[i][j] = 3;

  char str[100];
  int X, Y;
  while(M--){
    //cin>>str>>X>>Y;
    scanf("%s %d %d", str, &X, &Y);
    X -= 1; Y -= 1;
    if(str[0] == 'o')       ori[X][Y] = 3;
    else if(str[0] == '+')  ori[X][Y] = 2;
    else                    ori[X][Y] = 1;
    visit[X][Y] = 1;
    Fill(X, Y, ori[X][Y]);
    visit[X][Y] = 0;
    //printf("ori[%d][%d] = %d\n", X, Y, ori[X][Y]);
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      //cout<<arr[i][j]<<" ";
      oriarr[i][j] = arr[i][j];
    }
    //cout<<endl;
  }
  //cout<<endl;
}

void sol(int x, int y){
  memset(visit, 0, sizeof(visit));
  visit[x][y] = 1;
  Fill(x, y, arr[x][y]);
  int temp = 0, dif = 0;
  //printf("From (%d, %d):\n", x, y);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      visit[i][j] = 1;
      Fill(i, j, arr[i][j]);
      if(arr[i][j] > 1) temp += (arr[i][j] - 1);
      else if(arr[i][j]) temp += 1;
      if(arr[i][j] != ori[i][j]) dif++;
      //cout<<arr[i][j]<<" ";
      /*
      int lo = 0;
      cin>>lo;
      lo++;
      */
    }
    //cout<<endl;
  }
  /*
  printf("sum = %d\n", temp);
  cout<<endl;
  */
  if(temp > sum){
    diff = dif;
    sum = temp;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) ans[i][j] = arr[i][j];
  }
}

int main(void){
  int i, j, t;
  cin>>T;
  for(t= 1; t <= T; t++){
    ini();
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        for(int x = 0; x < N; x++) for(int y = 0; y < N; y++) arr[x][y] = oriarr[x][y];
        sol(i, j);
      }
    }
    /*
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++) cout<<ans[i][j]<<" ";
      cout<<endl;
    }
    */
    cout<<"Case #"<<t<<": "<<sum<<" "<<diff<<endl;
    for(i = 0; i < N; i++){
      for(j = 0; j < N; j++){
        if(ans[i][j] != ori[i][j]){
          if(ans[i][j] == 1)      cout<<"x ";
          else if(ans[i][j] == 2) cout<<"+ ";
          else                    cout<<"o ";
          cout<<i + 1<<" "<<j + 1<<endl;;
        }
      }
    }
  }
}
