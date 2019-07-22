/*
  cmp: 
  PT:
  LN:
  Polygon:

 */
#include <iostream>
#include <cmath>

const double eps = 1e-8;
int cmp( double x ) {
  if( fabs(x) < eps ) return 0;
  if( x > 0 ) return 1;
  return -1;
}

const double pi = acos( -1. );
inline double sqr( double x ){ return x * x; }
struct PT{
  double x, y;
  PT( const double &a = 0, const double &b = 0 ): x(a), y(b){}
  PT operator + ( const PT &a ) const{
    return PT( x + a.x, y + a.y);
  }
  PT operator - ( const PT &a ) const{
    return PT( x - a.x, y - a.y );
  }

  PT operator * ( const double &a ) const{
    return PT( x * a, y * a );
  }
  friend PT operator * ( const double &a, const PT &b ){
    return PT( a * b.x, a * b.y );
  }

  PT operator / ( const double &a ) const{
    return PT( x / a, y / a );
  }
  double norm(){ return sqrt( sqr(x) + sqr(y) ); }
};
double det(const PT &a, const PT &b){ return a.x * b.y - a.y * b.x; }
double dot(const PT &a, const PT &b){ return a.x * b.x + a.y * b.y; }
double dist(const PT &a, const PT &b){ return (a - b).norm(); }
PT rotate(const PT &a, const double &b){
  double x = a.x, y = a.y;  //原書上的，不知道這樣會比較快還是慢呢？
  return PT( x * cos(b) - y * sin(b), x * sin(b) + y * cos(b) );
}

struct LN{
  PT x, y; // x -> y
  LN( const PT &a = PT(), const PT &b = PT() ): x(a), y(b){}
};
/*LN 2LN(const PT &a, const PT &b){ return LN(a, b); }*/ //不不不，這真的看起來太沒用了(ㄨㄟ ˋ
double dist(const PT &a, const LN &b){
  if( cmp( dot(a - b.x, b.y - b.x) ) < 0 ) return (a - b.x).norm();
  if( cmp( dot(a - b.y, b.x - b.y) ) < 0 ) return (a - b.y).norm();
  return fabs( det( a - b.x, a - b.y ) / dist( b.x, b.y ) );
}
void ProjPT(const PT &a, const LN &b, PT &c ){  //c為a投射到LN之點
  c = b.x + (b.y - b.x) * ( dot(a - b.x, b.y - b.x) / dot(b.y - b.x, b.y - b.x) );
}
bool PTonLN(const PT &a, const LN &b){  //同射線上 => 線段內 (==0 : 含端點)
  return cmp( det(a - b.x, b.y - b.x) ) == 0 && cmp( dot(a - b.x, a - b.y) ) <= 0;
}
bool parallel(const LN &a, const LN &b){
  return cmp( det(a.y - a.x, b.y - b.x) ) == 0;
}
bool LNcross(const LN &a, const LN &b, PT &c){
  if( parallel(a, b) ) return false;
  double s1 = det( a.x - b.x, b.y - b.x ), s2 = det( a.y - b.x, b.y - b.x );
  c = (s1 * a.y - s2 * a.x) / (s1 - s2);
  return true;
}
LN move(const LN &a, const double &d){
  PT u = a.y - a.x;
  u = u / u.norm();
  u = rotate(u, pi / 2);
  return LN(a.x + u * d, a.y + u * d);
}

int N;
PT pt[505];
void ini( void ){
  for(int i = 0; i < N; ++i) scanf("%lf%lf", &pt[i].x, &pt[i].y);
}

void adjust( const PT &a, const PT &b, const PT &c, PT &d ){
  LN x( PT((a.x + b.x) / 2, (a.y + b.y) / 2) ), y( PT( (a.x + c.x) / 2, (a.y + c.y) / 2) );
  x.y = PT( x.x.x + x.x.y - a.y, x.x.y + x.x.x - a.x );
  y.y = PT( y.x.x + y.x.y - a.y, y.x.y + y.x.x - a.x );
  LNcross(x, y, d);
}

void sol( void ){
  PT O = pt[0];
  double r = 0;
  for(int i = 1; i < N; ++i){
    if( cmp( dist(O, pt[i]) - r ) <= 0 ) continue;
    O = pt[i], r = 0; 
    for(int j = 0; j < i; ++j){
      if( cmp( dist(O, pt[j]) - r ) <= 0 ) continue;
      O = ( pt[i] + pt[j] ) / 2, r = dist( pt[i], pt[j] ) / 2;
      for(int k = 0; k < j; ++k){
        if( cmp( dist(O, pt[k]) - r ) <= 0 ) continue;
        adjust( pt[i], pt[j], pt[k], O );
        r = dist(O, pt[k]);
      }
    }
  }
  printf("%.2lf %.2lf %.2lf\n", O.x, O.y, r);
}

int main(void){
  while( scanf("%d", &N) && N ){
    ini();
    sol();
  }
}
