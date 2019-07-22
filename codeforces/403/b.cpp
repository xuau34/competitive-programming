#include <bits/stdc++.h>
using namespace std;
int T, N, pos[60005], va[60005];
double L, R;

void ini(void){
  int i;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", pos + i);
  }
  for(i = 0; i < N; i++){
    scanf("%d", va + i);
  }
}

double idonkn(double x){
  int i;
  double Y = 0, j;
  for(i = 0; i < N; i++){
    j = abs(x - pos[i]) / va[i];
    Y = (j - Y > 0)? j: Y;
    //cout<<"in "<<x<<" the "<<i<<"th gets "<<j<<endl;
  }
  return Y;
}

void sol(void){
  const double exp = 0.000001;
  double ml, mr, div, mlm, mrm;
  L = 0;
  R = 1000000000;
  while((R - L) > exp){
    div = (R - L) / 3;
    ml = L + div;
    mr = L + div * 2;
    mlm = idonkn(ml);
    mrm = idonkn(mr);
    //cout<<"L = "<<L<<", R = "<<R<<": check "<<ml<<":"<<mlm<<" , "<<mr<<":"<<mrm<<" => ";
    if(mlm - mrm > 0){
      L = ml;
    }else R = mr;
    //cout<<"L = "<<L<<", R = "<<R<<endl;
    //scanf("%d", &T);
  }
  printf("%.12lf\n", idonkn(R));
}

int main(void){
  int i, j;

  ini();

  sol();

}
