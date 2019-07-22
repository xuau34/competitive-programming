#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
string A, B;
void ini(void){
  cout << 'f' - 'z' << endl;
  for(int i = 1; i < 27; ++i) cout << i << " ";
  cout << endl;
  for(int i = 0; i < 26; ++i) cout << (char) ('a' + i) << " ";
  cout << endl;
  cin >> N;
  cin >> A >> B;
}

void sol(void){
  int pivot = 0;
  char str[N + 1];
  for( int i = N - 1, sum; i >= 0; --i ){
    cout << A[i] - 'a' + 1 << " vs " << B[i] - 'a' + 1 << endl;
    if( B[i] < A[i] ){
      sum = (pivot + 'z' - A[i] + 1 + B[i] - 'a' + 2) / 2;
      pivot = (A[i] + sum - 1) > 'z';
      str[i] = (A[i] + sum - 1 - 'a') % 26 + 'a';
      //str[i] = 'a' - 1 + (sum % 26);
    }else{
      sum = (pivot + A[i] + B[i] - 'a' * 2 + 2);
      if( sum & 1 ){
        sum = (pivot + 'z' - A[i] + 1 + B[i] - 'a' + 2) / 2;
        pivot = (A[i] + sum - 1) > 'z';
        str[i] = (A[i] + sum - 1 - 'a') % 26 + 'a';
      }else{
        sum >>= 1;
        pivot = sum / 26;
        str[i] = 'a' - 1 + (sum % 26);
      }
    }
    cout << pivot << ", " << sum << " = > " << (sum % 26) << str[i] << endl;
  }
  str[ N ] = '\0';
  cout << str << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
