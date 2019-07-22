#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  //scanf("%d %d %d", &T, &N, &M);
  cin>>T>>N>>M;
}

long long sol(void){
  if(N + M < T) return -1;
  if(N % T && M < T) return -1;
  if(M % T && N < T) return -1;
  //cout<<(long long)(N / T)<<","<<(long long)(M / T)<<endl;
  return (long long)(N / T) + (long long)(M / T);
}

int main(void){
  int i, j;

  ini();

  //printf("%I64d\n",sol());
  cout<<sol()<<endl;

}
