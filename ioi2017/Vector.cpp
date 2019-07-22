#include <bits/stdc++.h>
using namespace std;
double EPS = 0.000001;
typedef pair<double, double> pdd;

pdd operator+ (const pdd &x, const pdd &y){
  return pdd(x.first + y.first, x.second + y.second);
}

pdd operator- (const pdd &x, const pdd &y){
  return pdd(x.first - y.first, x.second - y.second);
}

pdd operator* (const pdd &x, const double &y){
  return pdd(x.first * y, x.second * y);
}

pdd operator/ (const pdd &x, const double &y){
  return pdd(x.first / y, x.second / y);
}

double dot(const pdd &x, const pdd &y){
  return x.first * y.first + x.second * y.second;
}

double cross(const pdd &x, const pdd &y){
  return x.first * y.second - x.second * y.first;
}

double abs2(const pdd &x){
  return dot(a, a);
}

double abs(const pdd &x){
  return sqrt(dot(a, a));
}

int ori(const pdd &y, const pdd &x, const pdd &X){  // 1: X在xy的左; 0: 三點共線; -1: X在xy的右;
  double res = cross(x - y, X - y);
  if(abs(res) < EPS) return 0;
  return res > 0 ? 1: -1;
}

bool eps_equal (const double &x, const double &y){
  return abs(x - y) <= EPS;
}

bool eps_less (const double &x, const double &y){
  return a < b - EPS;
}

bool eps_greater (const double &x, const double &y){
  return a > b + EPS;
}

int T, N, M, Q;

int main(void){
  int i, j;

}
