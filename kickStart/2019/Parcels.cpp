#include "bits/stdc++.h"
using namespace std;
int ways[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, rows, cols, grid[255][255];

bool check(int X){
  if(X == 0){
    for( int i = 0; i < rows; ++i ){
      for( int j = 0; j < cols; ++j ) if(grid[i][j] == 0) return false;
    }
    return true;
  }
  vector< vector<bool> > valid( rows, vector<bool>(cols, 0) );
  vector< pair<pair<int, int>, int> > 
  for( int i = 0; i < rows; ++i ){
    for( int j = 0; j < cols; ++j ){
      if()
    }
  }
}

int main(void){
  int Tcase;
  cin >> Tcase;
  for( int Case = 1; Case <= Tcase; ++Case){
    cin >> rows >> cols;
    if(rows + cols == 0){
      printf("Case #%d: %d\n", Case, 0);
      continue;
    }
    offices.clear();
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols;++j){
        char c;
        cin >> c;
        grid[i][j] = c - '0';
        if( grid[i][j] ) offices.push_back( make_pair(i,j) );
      }
    }
    int L = -1, M, R = rows + cols;
    while( L + 1 < R ){
      M = (L + R) >> 1;
      if( check(M) ) R = M;
      else L = M;
    }
    printf("Case #%d: %d\n", Case, R);
  }
}
