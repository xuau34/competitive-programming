#include <bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
map<PII, int> ma;
map<PII, int>::iterator ite1;
map<pair<PII, int>, int> m;
map<pair<PII, int>, int>::iterator ite;
int x, y, dir[8][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
void new_way(void){
  map<pair<PII, int>, int> temp;
  int j;
  for(ite = m.begin();ite != m.end(); ite++){
    x = (ite->X).X.X;
    y = (ite->X).X.Y;
    j = (ite->X).Y - 1;
    if(j < 0) j += 8;
    temp[MP(MP(x + dir[j][0], y + dir[j][1]), j)] = 1;
    ma[MP(x + dir[j][0], y + dir[j][1])] = j;
    j = (ite->X).Y + 1;
    if(j > 7) j = 0;
    temp[MP(MP(x + dir[j][0], y + dir[j][1]), j)] = 1;
    ma[MP(x + dir[j][0], y + dir[j][1])] = j;
  }
  m = temp;
}
void Move(int mm){
  map<pair<PII, int>, int> temp;
  int j;
  for(ite = m.begin(); ite != m.end(); ite++){
    x = (ite->X).X.X;
    y = (ite->X).X.Y;
    if(mm == 1)
      temp[MP(MP(x, y), (ite->X).Y)] = 1;
    for(j = 1; j < mm; j++){
      x += dir[(ite->X).Y][0];
      y += dir[(ite->X).Y][1];
      if(j != mm -1){ 
        ma[MP(x,y)] = -1;
      }else{
        temp[MP(MP(x, y), (ite->X).Y)] = 1;
        ma[MP(x, y)] = (ite->X).Y;
      }
    }
  }
  m = temp;
}
int main(void){
  int n, i, mm, j;
  scanf("%d", &n);
  m[MP(MP(0, 0), 0)] = 1;
  ma[MP(0,0)] = 1;
  for(i = 0; i < n; i++){
    if(i) new_way();
    scanf("%d", &mm);
    Move(mm);
  }
  cout<<ma.size()<<endl;
}
