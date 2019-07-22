#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;

void ini(void){
  scanf("%d%d", &N, &M);
}

bool sol(void){
  Q = __gcd(N, M);
  cout << "1 " << Q << " " << endl;
  if(Q == 1) return false;
  long long ans = 0, hi = 0;
  while(N > 1){
    N /= Q;
    ++ans;
  }
  while(M > 1){
    M /= Q;
    ++ans;
  }
  
  cout << "2 " << ans  << " " << endl;
  if(ans % 3 == 0) return true;

  for(int i = 2; Q > 1; ++i){
    while(Q > 1 && Q % i == 0){
      ++hi;
      Q /= i;
    }
  }

  cout << "3" << " " << endl;
  if(Q % 3 == 0) return 1;
  else return 0;
}

int main(void){
  int i, j;

  scanf("%d", &T);
  while(T--){
    ini();
    if( sol() ) printf("Yes\n");
    else printf("No\n");
  }

}
