#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
pair<int, int> A[10], B[10];
int a[10], b[10];
void ini(void){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> A[i].first >> A[i].second;
  }
  for(int i = 0; i < M; i++){
    cin >> B[i].first >> B[i].second;
  }
  sort( A, A + N );
  sort( B, B + M );
  cout<<"A:";
  for(int i = 0; i < N; i++) cout<<A[i].first << ","<<A[i].second <<" ";
  cout<<endl;
  cout<<"B:";
  for(int i = 0; i < M; i++) cout<<B[i].first << ","<<B[i].second <<" ";
  cout<<endl;
  if(!N){
    a[0] = 1440;
    ++N;
  }else{
    if(N > 1 && A[0].first > 0 && A[N - 1].second < 1440){
      a[0] = A[0].first + 1440 - A[N - 1].second;
    }else{
      a[0] = A[0].first - A[N - 1].second;
    }
    for(int i = 1; i < N - 1; i++){
      a[i] = A[i].first - A[i - 1].second;
      if(a[i] < 0) a[i] += 1440;
    }
  }
  if(!M){
    b[0] = 1440;
    ++M;
  }else{
    if(M > 1 && B[0].first > 0 && B[N - 1].second < 1440){
      b[0] = B[0].first + 1440 - B[N - 1].second;
    }else{
      b[0] = B[0].first - B[M - 1].second;
    }
    for(int i = 0; i < M - 1; i++){
      b[i] = B[i].first - B[i - 1].second;
      if(b[i] < 0) b[i] += 1440;
    }
  }
  sort( a, a + N );
  sort( b, b + M );
  for(int i = 0; i < N ;i++) cout<<a[i]<<" ";
  cout<<endl;
  for(int i = 0; i < M ;i++) cout<<b[i]<<" ";
  cout<<endl;
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
  cout << max(ans, ans2) * 2 << endl;
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
