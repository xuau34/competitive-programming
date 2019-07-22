#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
long long n, k;
int main(void){
  long long i, j;
  cin>>n>>k;
  if(n & 1) i = (long long)(n / 2) + 1ull;
  else i = n / 2;
  if(k <= i) cout<<2 * (k - 1) + 1<<endl;
  else cout<<2 * (k - i)<<endl;
}
