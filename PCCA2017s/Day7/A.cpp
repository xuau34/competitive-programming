#include <bits/stdc++.h>
using namespace std;
int T, N, Q;
map<string, vector<string> > M;
void ini(void){
  cin >> N;
}

void sol(void){
  int n, m;
  string str, HI, acc, mail;
  while(N--){
    cin >> str;
    n = str.find( '@' );
    //printf("find @ in %d: ", n);
    acc = str.substr(0, n);
    mail = str.substr(n + 1);
    //cout << acc << " " << mail << " => ";
    for(int i = 0, j = acc.length(); i < j; ++i) acc[i] = tolower(acc[i]);
    for(int i = 0, j = mail.length(); i < j; ++i) mail[i] = tolower(mail[i]);
    //cout << acc << " " << mail << endl;

    if( mail == "bmail.com"){
      HI.clear();
      for(int i = 0, j = acc.length(); i < j && acc[i] != '+'; ++i)
        if(acc[i] != '.') HI.push_back( acc[i] );
      M[HI+"@"+mail].push_back(str);
      //cout << "HI = " << HI << endl;
    }else M[acc+"@"+mail].push_back(str);
    //printf("HI = %s\n", HI.c_str() );

/*
    for(auto i: M){
      printf("%s %d ", i.first.c_str(), i.second.size() );
      for(auto j: i.second) cout << j << " ";
      printf("\n");
    }
    */
  }
  printf("%d\n", M.size());
    for(auto i: M){
      printf("%d ", i.second.size() );
      for(auto j: i.second) cout << j << " ";
      printf("\n");
    }
}

int main(void){
  int i, j;

  ini();

  sol();

}
