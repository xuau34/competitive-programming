#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> ma;
map<pair<int, int>, int>::iterator ite1;
map<pair<pair<int, int>, int>, int> m;
map<pair<pair<int, int>, int>, int>::iterator ite;
int x, y, dir[8][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
void new_way(void){
  map<pair<pair<int, int>, int>, int> temp;
  int j;
  for(ite = m.begin();ite != m.end(); ite++){
    x = (ite->first).first.first;
    y = (ite->first).first.second;
    //temp[make_pair(x, y)] = -1;
    ma[make_pair(x, y)] = -1;
    if((ite->first).second != -1){
      j = (ite->first).second - 1;
      if(j < 0) j += 8;
      temp[make_pair(make_pair(x + dir[j][0], y + dir[j][1]), j)] = 1;
      ma[make_pair(x + dir[j][0], y + dir[j][1])] = j;
      j = (ite->first).second + 1;
      if(j > 7) j = 0;
      temp[make_pair(make_pair(x + dir[j][0], y + dir[j][1]), j)] = 1;
      //temp[make_pair(x + dir[j][0], y + dir[j][1])] = j;
      ma[make_pair(x + dir[j][0], y + dir[j][1])] = j;
    }
  }
  m = temp;
  /*printf("new_way\n");
  for(ite = temp.begin(); ite!= temp.end(); ite++){
    printf("%d,%d : %d\n", (ite->first).first.first, (ite->first).first.second, (ite->first).second);
  }*/
}
void Move(int mm){
  map<pair<pair<int, int>, int>, int> temp;
  int j;
  for(ite = m.begin(); ite != m.end(); ite++){
    x = (ite->first).first.first;
    y = (ite->first).first.second;
    if(mm > 1){
      //temp[make_pair(x, y)] = -1;
      ma[make_pair(x, y)] = -1;
    }else{
      temp[make_pair(make_pair(x, y), (ite->first).second)] = 1;
      ma[make_pair(x, y)] = ite->second;
    }
    for(j = 1; j < mm; j++){
      if((ite->first).second != -1){
        x += dir[(ite->first).second][0];
        y += dir[(ite->first).second][1];
        if(j != mm -1){ 
          //temp[make_pair(x,y)] = -1;
          ma[make_pair(x,y)] = -1;
        }else{
          temp[make_pair(make_pair(x, y), (ite->first).second)] = 1;
          ma[make_pair(x, y)] = (ite->first).second;
        }
      }
  //for(map<pair<int, int>, pair<int, int> >::iterator it = m.begin(); it!= m.end(); it++){
    //printf("%d,%d : %d\n", (it->first).first, (it->first).second, (it->second).first);
  //}
    }
  }
  m = temp;
}
int main(void){
  int n, i, mm, j;
  scanf("%d", &n);
  m[make_pair(make_pair(0, 0), 0)] = 1;
  for(i = 0; i < n; i++){
    if(i) new_way();
    /*printf("new_way\n");
    for(ite1 = ma.begin(); ite1!= ma.end(); ite1++){
      printf("%d,%d : %d\n", (ite1->first).first, (ite1->first).second, ite->second);
    }
    cout<<ma.size()<<endl;
    printf("\n");*/
    scanf("%d", &mm);
    Move(mm);
    /*printf("Move\n");
    for(ite1 = ma.begin(); ite1!= ma.end(); ite1++){
      printf("%d,%d : %d\n", (ite1->first).first, (ite1->first).second, ite->second);
    }*/
  }
  cout<<ma.size()<<endl;
}
