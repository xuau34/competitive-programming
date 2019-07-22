#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
typedef struct _v{
  string a, o, b;
} value;
map<string, string> known;
map<string, value> unknown;
map<string, value>::iterator ite;;
string str, x, y, z;
void ini(void){
  int i;
  cin>>N>>M;
  for(i = 0; i < N; i++){
    cin>>str;
    cin>>x;
    cin>>x;
    if(x[0] >= '0' && x[0] <= '9'){
      known[str] = x;
    }else{
      cin>>y>>z;
      unknown[str].a = x;
      unknown[str].o = y;
      unknown[str].b = z;
    }
  }
}

void sol(void){
  int i, j;
  for(i = 0; i < M; i++){
    for(ite = unknown.end())
  }
}

int main(void){
  int i, j;

  ini();

  sol();

}
