#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
map<string, int> m;
string str;
void ini(void){
  m["Tetrahedron"] = 4;
  m["Cube"] = 6;
  m["Octahedron"] = 8;
  m["Dodecahedron"] = 12;
  m["Icosahedron"] = 20;
  M = 0;
  cin>>N;
  while(N--){
    cin>>str;
    M += m[str];
    //cout<<M<<endl;
  }
    cout<<M<<endl;
}

void sol(void){

}

int main(void){
  int i, j;

  ini();

  sol();

}
