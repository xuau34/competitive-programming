#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
#define Time 15
using namespace std;
long long A, B;

long long mult_mod(long long x, long long y, long long p){
  long long ret = 0;
  x %= p, y %= p;
  //cout<<"mult_mod("<<x<<" * "<<y<<" % "<<p<<"): ";
  while(y){
    if(y & 1) ret = (ret + x) % p; 
    //cout<<ret<<" ";
    x = (x << 1) % p;
    y >>= 1;
  }
  //cout<<ret<<endl;
  return ret;
}

long long pow_mod(long long x, long long y, long long p){
  //cout<<"pow_mod("<<x<<" ^ "<<y<<" % "<<p<<"): ";
  x %= p;
  if(y == 1) return x;
  long long tmp = x, ret = 1;
  while(y){
    if(y & 1) ret = mult_mod(ret, tmp, p);
    tmp = mult_mod(tmp, tmp, p);
    //cout<<ret<<" ";
    y >>= 1;
  }
  //cout<<endl;
  return ret;
}

bool check(long long b, long long x, long long y, long long t){
  long long ret = pow_mod(b, x - 1, y), last = ret;
  //cout<<"check(base = "<<b<<", x = "<<x<<", n = "<<y<<", t = "<<t<<") : ret = "<<ret<<endl;
  for(int i = 1; i <= t; i++){
    //cout<<"mult_mod("<<ret<<"^2, "<<y<<") = "<<mult_mod(ret, ret, y)<<endl;
    ret = mult_mod(ret, ret, y);
    if(ret == 1 && last != 1 && last != y - 1) return true; //合
    last = ret;
  }
  if(ret != 1) return true;
  return false;
}

bool Miller_Rabin(long long n){   //快速檢查是否為質數，以上都要。
  if(n < 2) return false;
  if(n < 4 || n == 19 || n == 71 || n == 97) return true;
  if(!(n & 1) || !(n % 19) || !(n % 71) || !(n % 97)) return false;
  long long x = n - 1, t = 0;
  while(!(x & 1)){
    x >>= 1;
    t++;
  }
  //long long pr[5] = {19, 71, 97};
  for(int i = 0; i < Time; i++){
    long long a = (rand() % (n - 1)) + 1;
    //printf("base = %lld\n", pr[i]);
    if(check(a, n, n, t)) return false;
  }
  return true;
}


long long T, N, M, Q;

void ini(void){
  scanf("%lld%lld", &N, &M);
  for(long long i = N; i <= M; ++i){
    if(Miller_Rabin(i)) printf("%lld\n", i);
  }
  printf("\n");
  /*
  if(Miller_Rabin(N)){
    cout<<"no"<<endl;
    return;
  }
  long long m = N, b = M, ans = 1;
  while(m){
    if(m & 1) ans = (ans * b) % N;
    b = (b * b) % N;
    m >>= 1;
  }
  if(ans == M) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
  */
}


int main(void){
  int i, j;
  scanf("%lld", &T);
  while(T--){
    ini();
  }
}
