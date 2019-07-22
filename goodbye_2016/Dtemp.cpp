#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> ma;
map<pair<int, int>, int>::iterator ite1;
multimap<pair<int, int>, int> m;
multimap<pair<int, int>, int>::iterator ite;
int x, y, dir[8][2] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
void new_way(void){
  multimap<pair<int, int>, int> temp;
  int j;
  for(ite = m.begin();ite != m.end(); ite++){
    x = (ite->first).first;
    y = (ite->first).second;
    //temp[make_pair(x, y)] = -1;
    ma[make_pair(x, y)] = -1;
    if(ite->second != -1){
      j = ite->second - 1;
      if(j < 0) j += 8;
      temp.insert(make_pair(make_pair(x + dir[j][0], y + dir[j][1]), j));
      ma[make_pair(x + dir[j][0], y + dir[j][1])] = j;
      j = ite->second + 1;
      if(j > 7) j = 0;
      temp.insert(make_pair(make_pair(x + dir[j][0], y + dir[j][1]), j));
      //temp[make_pair(x + dir[j][0], y + dir[j][1])] = j;
      ma[make_pair(x + dir[j][0], y + dir[j][1])] = j;
    }
  }
  m = temp;
  printf("new_way\n");
  for(ite = temp.begin(); ite!= temp.end(); ite++){
    printf("%d,%d : %d\n", (ite->first).first, (ite->first).second, ite->second);
  }
}
void Move(int mm){
  multimap<pair<int, int>, int> temp;
  int j;
  for(ite = m.begin(); ite != m.end(); ite++){
    x = (ite->first).first;
    y = (ite->first).second;
    if(mm > 1){
      //temp[make_pair(x, y)] = -1;
      ma[make_pair(x, y)] = -1;
    }else{
      temp.insert(make_pair(make_pair(x, y), ite->second));
      ma[make_pair(x, y)] = ite->second;
    }
    for(j = 1; j < mm; j++){
      if(ite->second != -1){
        x += dir[ite->second][0];
        y += dir[ite->second][1];
        if(j != mm -1){ 
          //temp[make_pair(x,y)] = -1;
          ma[make_pair(x,y)] = -1;
        }else{
          temp.insert(make_pair(make_pair(x, y), ite->second));
          ma[make_pair(x, y)] = ite->second;
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
  m.insert(make_pair(make_pair(0, 0), 0));
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
}
