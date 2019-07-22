#include <bits/stdc++.h>
#include <stdlib.h>
#define Time 15
using namespace std;
int T, N, M, Q;
vector<long long> factor;
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
  //cout<<endl;
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

bool Miller_Rabin(long long n){
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

long long Pollard_rho(long long x, long long c){
  long long i = 1, k = 2, x0 = rand() % x, y = x0;
  //cout<<"x = "<<x<<", x0 = "<<x0<<", y = "<<y<<endl;
  while(1){
    i++;
    x0 = (mult_mod(x0, x0, x) + c) %x;
    /*
    cout<<"x0 = "<<x0<<", y = "<<y<<endl;
    int xx;
    while(cin>>xx && xx);
    */
    long long d = __gcd((y - x0 + x) % x, x);
    if(d != 1 && d != x) return d;
    if(y == x0) return x;
    if(i == k){
      y = x0;
      k += k;
    }
  }
}

void findfac(long long n){
  if(Miller_Rabin(n)){
    factor.push_back(n);
    return;
  }
  long long p = n;
  while(p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
  //cout<<"p = "<<p<<", n / p = "<<n/p<<endl;
  findfac(p);
  findfac(n / p);
}

int main(void){
  long long i;
  
  srand(time(NULL));  //POJ上的G++會GG

  /*
  while(cin>>i){
    cout<<Miller_Rabin(i)<<endl;
  }
  */

  while(cin>>i){
    findfac(i);
    for(int v: factor){
      cout<<v<<" ";
    }
    cout<<endl;
    factor.clear();
  }

}
