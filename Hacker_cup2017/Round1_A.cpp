#include <bits/stdc++.h>
using namespace std;
bool f1(double x, double y){
  double Y = (x - 50) * (x - 50) + (y - 50) * (y - 50);
  return ((Y > 2500)? false: true);
}
double len(double x, double y){
  return sqrt(x * x + y * y);
}
int main(void){
  int N, n, i, s;
  double p, x, y, X = 0, Y = 50.0, theta;
  scanf("%d", &N);
  for(n = 1; n <= N; n++){
    s = 0;
    cin>>p>>x>>y;
    if(f1(x, y)){
      if(y == 50.0){
        if(x == 50.0 && p > 0.0) s = 1;
        else if(x > 50.0 && p >= 25.0) s = 1;
        else if(x < 50.0 && p >= 75.0) s = 1;
      }else{
        x -= 50;
        y -= 50;
        cout<<x<<","<<y<<endl;
        //theta = (acos((x*X + y*Y)/(len(x, y) * len(X, Y)))/acos(-1))/360;
        theta = acos((x*X + y*Y)/(len(x, y) * len(X, Y)));
        cout<<theta<<endl;
        cout<< theta*180/acos(-1)<<"          !"<<endl;
        theta = theta/(2*acos(-1));
        cout<<theta<<endl;
        if(theta <= p/100) s = 1;
      }
    }else s = 0;
      if(s) printf("Case #%d: black\n", n);
      else printf("Case #%d: white\n", n);
  }
}
