#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
pair<int, int> A[10], B[10];
pair<int, pair<int, int> > a[10], b[10];
void ini(void){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> A[i].first >> A[i].second;
    a[i].first = A[i].second - A[i].first;
    if(a[i].first < 0) a[i].first += 1440;
    a[i].second = A[i];
  }
  for(int i = 0; i < M; i++){
    cin >> B[i].first >> B[i].second;
    b[i].first = B[i].second - B[i].first;
    if(b[i].first < 0) b[i].first += 1440;
    b[i].second = B[i];
  }
  sort( a, a + N );
  sort( b, b + M );
  sort( A, A + N );
  sort( B, B + M );
}

bool canget(bool who, int l, int r, int mi){
  int get = 0, tmp;
  if(who){
    for(int i = 0; i < N; i++){
      if(A[i].first < l || A[i].second >= r) continue;
      tmp = A[i].second - A[i].first;
      if(tmp < 0) tmp += 1440;
      get += tmp;
    }
  }else{
    for(int i = 0; i < M; i++){
      if(B[i].first < l || B[i].second >= r) continue;
      tmp = B[i].second - B[i].first;
      if(tmp < 0) tmp += 1440;
      get += tmp;
    }
  }
  if(get >= mi) return true;
}

void sol(void){
  int ans = Q = 0, ans2 = 0;
  for(int i = N - 1; i >= 0; i--){
    Q += a[i];
    ans++;
    if(Q >= 720) break;
  }
  Q = 0;
  for(int i = M - 1; i >= 0; i--){
    Q += b[i];
    ans2++;
    if(Q >= 720) break;
  }
  cout << ans << "vs" << ans2 << " ";
  cout << min(ans, ans2) * 2 << endl;
}

int main(void){
  int t;
  cin >> T;
  for(t = 1; t <= T; t++){
    ini();
    cout<<"Case #"<<t<<": ";
    sol();
  }
}
