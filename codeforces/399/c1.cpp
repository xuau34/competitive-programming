#include <bits/stdc++.h>
using namespace std;
int T, N, K, X;
vector<pair<int, int> > ans;
map<multiset<int>, int> m;
map<multiset<int>, int>::iterator ite;
multiset<int> s;

void ini(void){
  int i, j;
  scanf("%d %d %d", &N, &K, &X);
  for(i = 0; i < N; i++){
    scanf("%d", &j);
    s.insert(j);
  }
  m[s] = 0;
  /*
  for(int v: s){
    cout<<v<<" ";
  }
  cout<<endl;
  cout<<*(s.rbegin())<<" "<<*(s.begin())<<endl;
  */
  ans.push_back( make_pair( *(s.rbegin()), *(s.begin() ) ) );
}

void sol(void){
  int i, j;
  for(i = 1; i <= K; i++){
    multiset<int> s1;
    j = 1;
    for(int v : s){
      if(j){
        s1.insert(v ^ X);
        j = 0;
      }else{
        s1.insert(v);
        j = 1;
      }
    }
    /*
    printf("---\ns1: ");
    for(int v: s1){
      cout<<v<<" ";
    }
    cout<<endl;

    for(ite = m.begin(); ite != m.end(); ite++){
      s = ite -> first;
      for(int v: s){
        printf("%d ", v);
      }
      printf(": %d\n", ite->second);
    }
    printf("---\n");
    */

    ans.push_back( make_pair( *(s1.rbegin()), *(s1.begin() ) ) );
    if(m.find(s1) == m.end()){
      m[s1] = i;
    }else{
      i = (K - m[s1]) % (i - m[s1]) + m[s1] + 1;
      break;
    }
    s = s1;
  }
  --i;
  //cout<<"in "<<i<<endl;
  printf("%d %d\n", ans[i].first, ans[i].second);
}

int main(void){
  int i, j;

  ini();

  sol();

}
