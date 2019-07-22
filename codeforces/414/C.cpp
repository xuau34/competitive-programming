#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
string A, B, C;
int l, a, b, ae = A.size() - 1, be = B.size() - 1, c, d;
void ini(void){
  cin >> A >> B;
  sort( A.begin(), A.end() );
  sort( B.begin(), B.end() );
  l = A.size();
  a = c = 0;
  be = B.size() - 1;
  C.resize( l );
  d = l - 1;
  if( l & 1){
    ae = (A.size() / 2);
    b = (B.size() / 2) + 1;
  }else{
    ae = (A.size() / 2) - 1;
    b = B.size() / 2;
  }
  //cout << ae << "," << b << endl;
}

void sol(void){
  for( int i = 0; i < l; ++i){
    if( i & 1 ){
      if(B[ be ] > A[a] ){
        C[c++] = B[be--];
      }else{
        C[d--] = B[b++];
      }
    }else{
      if(A[a] < B[ be ] ){
        C[c++] = A[a++];
      }else{
        C[d--] = A[ae--];
      }
    }
  }
  cout << C << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
