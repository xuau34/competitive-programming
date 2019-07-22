#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
const double PI = acosl(-1);

void preFFT(void){
  for(i = 0; i <= N; i++)
    omega[i] = exp(i * 2 * PI / MAX * I);
}

void FFT(int n, Type x[], bool inv = false){
  int basic = MAXN / N;
  int theta = basic;
  
  for(int m = n; m >= 2; m >>= 1){
    int mh = m >> 1;
    for(int i = 0; i < mh; i++){
      Type w = omega[inv ? MAXN - (i * theta % MAXN): i * theta % MAXN];
      for(int j = i; j < n; j+= m){
        int k = j + mh;
        Type X = x[j] - x[k];
        x[j] += x[k];
        x[k] = w * X;
      }
    }
    theta = (theta << 1) % MAXN;
  }

  int i = 0;
  for(int j = 1; j < n - 1; j++){
    for(int k = n >> 1; k > (i ^= k); k >>= 1);
    if(j < i) swap(x[i], x[j]);
  }

  if(inv)
    for(i = 0; i < n; i++) x[i] /= n;
}

vector<Type> Convolution(const vector<Type> &F, const vector<Type> &G){ //丟入二多項式
  vector<Type> F_value, G_value;
  int N = 1000;
  F_value = FFT(F, N);  //得點值式
  G_value = FFT(G, N);  // ``

  vector<Type> FG_value(N);
  for(int i = 0; i < N; i++)
    FG_value[i] = F_value[i] * G_value[i];  //得f*g之點值式
  
  return FFT(FG_value, N, 1); //回傳f*g之係數式
}
int main(void){
  int i, j;
  preFFT();

}
