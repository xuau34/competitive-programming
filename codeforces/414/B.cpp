#include <bits/stdc++.h>
using namespace std;
double T, N, H;

void ini(void){
  cin >> N >> H;
}

void sol(void){
  double ans;
  for(int i = 1; i < N; i++){
    cout <<setprecision(13) << (double)H * sqrt(i / N) << " ";
  }
  cout<<endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
