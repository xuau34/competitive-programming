#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char a[100005], b[100005];
void ini(void){
  cin>>a>>b;
}

void sol(void){
  if(strcmp(a, b)){
    cout<<max(strlen(a), strlen(b))<<endl;
  }else cout<<"-1"<<endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
