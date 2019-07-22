#include <bits/stdc++.h>
using namespace std;
typedef unsigned Ty;
typedef pair<Ty,Ty> PP;
int T, N, M, Q;
char X[MAXN], Y[MAXN];
PP h1[MAXN], h2[MAXN];
PP p(101, 101), q(1000000007,1000000009);

void Hash(const char *x, int n, pair<unsigned, unsigned> *h){
  for(int i = 0; i < n; i++){
    h[i].first = (h[i - 1].first * p1.first + x[i]) % q.first;
    h[i].second = (h[i - 1].second * p1.second + x[i]) & q.second;
  }
}

void Set(const PP *h, int L, int n, PP pl, PP *set){
  for(int i = 0; i < n - L + 1; i++){
    set[i].first = 
  }
}

int main(void){
  int i, j;
  scanf("%s%s", X, Y);
}
