#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
pair<char, int> A[150005], B[150005];
const bool deb = false;

void ini(void){
  cin >> N;
  string str;
  cin >> str;
  for(int i = 0; i < N; ++i) A[i] = make_pair(str[i], i);

  cin >> str;
  for(int i = 0; i < N; ++i) B[i] = make_pair(str[i], i);
  //for(int i = 0; i < N; ++i) cout << B[i].first << " " << B[i].second << endl;
}

void sol(void){
  sort(A, A + N), sort(B, B + N);
  vector< pair<int, int> > pii;
  int x = 0, y = 0, j;
  while(A[x].first == '?') ++x;
  while(B[y].first == '?') ++y;
  j = y;
  for(int i = x; i < N; ++i){
    while( j < N && B[j].first < A[i].first ){
      if(x){
        pii.push_back( make_pair( A[--x].second, B[j].second) );
      if(deb)   cout << A[i].first << A[i].second << " " << B[j].first << B[j].second << endl;
      }
      ++j;
    }
    if( j < N && A[i].first == B[j].first ){
      pii.push_back( make_pair(A[i].second, B[j].second) );
      if(deb) cout << A[i].first << A[i].second << " " << B[j].first << B[j].second << endl;
      ++j;
    }else if(y){
      pii.push_back( make_pair(A[i].second, B[--y].second) );
      if(deb) cout << A[i].first << A[i].second << " " << B[j].first << B[j].second << endl;
    }
  }
  while( j < N && x ) pii.push_back( make_pair( A[--x].second, B[j++].second) );
  while( x && y ) pii.push_back( make_pair( A[--x].second, B[--y].second) );
  cout << pii.size() << endl;
  for(pair<int,int> x:pii) cout << x.first + 1 << " " << x.second + 1 << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
