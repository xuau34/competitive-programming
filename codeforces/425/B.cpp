#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
bool good[500];
char str[100005], s[100005];
void ini(void){
  M = -1;
  scanf("%s", str);
  for(int i = 0, j = strlen(str); i < j; ++i) good[ str[i] ] = 1;
  scanf("%s%d", str, &Q);
  N = strlen(str);
  for(int i = 0; i < N; ++i) if( str[i] == '*' ) M = i;
}

bool sol(void){
  T = strlen(s);
  if(N - T > 1) return 0;
  if(T > N || N - T == 1){
    if(M < 0) return 0;
    for(int i = 0; i < M; ++i){
      if( str[i] == '?'){
        if(!good[s[i]]) return 0;
      }else if( str[i] != s[i] ){
        //printf("2");
        return 0;
      }
    }
    int i = 1;
    for(; N - i > M; ++i){
      //printf("str[%d] vs s[%d]\n", N - i, T - i);
      if( str[N - i] == '?' ){
        if(!good[s[T - i]]) return 0;
      }else if( str[N - i] != s[T - i] ){
        return 0;
      }
    }
    --i;
    //cout << i;
    for(int j = M; j < T - i; ++j){
      //printf("s[%d]\n", j);
      if( good[s[j]] ) return 0;
    }
  }else{
    for(int i = 0; i < N; ++i){
      if( str[i] == '?'){
        if(!good[s[i]]) return 0;
      }else if( str[i] == '*'){
        if(good[s[i]]) return 0;
      }else if( str[i] != s[i] ){
        //printf("2");
        return 0;
      }
    }
  }
  return 1;
}

int main(void){
  int i, j;

  ini();
  while(Q--){
    scanf("%s", s);
    if( sol() ) printf("YES\n");
    else printf("NO\n");
  }

}
