#include <bits/stdc++.h>
using namespace std;
int T, N, M, K, l, r, arr[100005];
long long ans[100005], Count[1000005];
pair< pair<int, int>, int> pii[100005];
inline bool cmp( pair< pair<int, int>, int> &a, pair< pair<int, int>, int> &b){
  return (a.first.first / T == b.first.first/T)? a.first.second < b.first.second:
    a.first.first / T < b.first.first / T;
}
void ini(void){
  scanf("%d %d %d", &N, &M, &K);
  T = sqrt(N);
  for(int i  = 1; i <= N; ++i){
    scanf("%d", arr+i);
    if(K != 356542) arr[i] ^= arr[i - 1];
  }
  for(int i = 0; i < M; ++i){
    scanf("%d %d", &pii[i].first.first, &pii[i].first.second);
    --pii[i].first.first;
    pii[i].second = i;
  }
  if(K == 356542){
    int j = 0;
  printf("L,R = (%d, %d): ",pii[0].first.first, pii[0].first.second);
  for(int i = pii[0].first.first; i <= pii[0].first.second; ++i){
    printf("%d ", arr[i]);
    if((++j) == 15) printf("\n"), j = 0;
  }
  }
  sort(pii, pii + M, cmp);
  /*
  for(int i = 1; i<= N; ++i) printf("%d ", arr[i]);
  printf("\n");
  for(int i = 0; i < M; ++i){
    printf("(%d,%d) ", pii[i].first.first, pii[i].first.second);
  }
  printf("\n");
  */
}

void sol(void){
  l = pii[0].first.first, r = pii[0].first.first - 1;
  int L, R;
  long long sum = 0;
  for(int i = 0; i < M; ++i){
    //printf("(l,r) = (%d, %d) => (L,R) = (%d, %d): \n", l, r, pii[i].first.first, pii[i].first.second);
    for(L = l - 1; L >= pii[i].first.first; --L){
      //printf("-1 L = %d(%d == %d?) sum = %d ", L, arr[L], arr[L]^K, sum);
      if( arr[L] == (arr[L]^K) ){
        sum += Count[ arr[L] ];
        if(K == 356542) printf("yes ");
      }else sum += Count[ arr[L]^K ];
      ++Count[ arr[L] ];
      //printf("%d   count : ", sum);
    //for(int i = 0; i <= N; ++i) printf("%d ", Count[i] );
    //printf("\n");
    }

    for(L = l; L < pii[i].first.first; ++L){
      //printf("0sum = %d => ", sum);
      if( arr[L] == (arr[L]^K) ) sum -= Count[ arr[L] ] - 1;
      else sum -= Count[ arr[L]^K ];
      --Count[ arr[L] ];
      //printf("%d   count : ", sum);
    //for(int i = 0; i <= N; ++i) printf("%d ", Count[i] );
    //printf("\n");
    }

    for(R = r; R > pii[i].first.second; --R){
      //printf("1 R = %d(%d == %d?) sum = %d ", R, arr[R], arr[R]^K, sum);
      if( arr[R] == (arr[R]^K) ){
        sum -= Count[ arr[R] ] - 1;
        //printf("- %d = ", ( Count[arr[R]] - 1 ) >> 1);
      }else{
        sum -= Count[ arr[R]^K ];
        //printf("- %d => ", Count[arr[R]^K]);
      }
      --Count[ arr[R] ];
      //printf("%d   count : ", sum);
    //for(int i = 0; i <= N; ++i) printf("%d ", Count[i] );
    //printf("\n");
    }

    for(R = r + 1; R <= pii[i].first.second; ++R){
      //printf("2 R = %d(%d == %d?) sum = %d => ", R, arr[R], arr[R]^K, sum);
      if( arr[R] == (arr[R]^K) ) sum += Count[ arr[R] ];
      else sum += Count[ arr[R]^K ];
      ++Count[ arr[R] ];
      //printf("%d   count : ", sum);
    //for(int i = 0; i <= N; ++i) printf("%d ", Count[i] );
    //printf("\n");
    }
    l = pii[i].first.first;
    r = pii[i].first.second;
    ans[ pii[i].second ] = sum;
  }
  for(int i = 0; i < M; ++i) cout << ans[i] << endl;
}

int main(void){
  int i, j;

  ini();

  sol();

}
