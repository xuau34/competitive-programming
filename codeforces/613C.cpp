/*
  將數字作拆解，拆成能與不能，能之後又能分幾組之類的，剩下就只需要對稱放就行了。
 */

#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q, arr[30];

void ini(void){
  scanf("%d", &N);
  for(int i = 0; i < N; ++i){
    scanf("%d", arr + i);
    if(arr[i] & 1) ++M;
  }
}

int check(void){
  int ret = 0;
  for(int i = 0; i < N; ++i) if((arr[i] / Q) & 1) ++ret, T = i;
  return ret;
}

void sol(void){
  if(M > 1){
    printf("0\n");
    for(int i = 0; i < N; ++i) for(int j = 0; j < arr[i]; ++j) printf("%c", i + 'a');
    printf("\n");
  }else{
    Q = arr[0];
    for(int i = 1; i < N; ++i) Q = __gcd(Q, arr[i]);
    printf("%d\n", Q);
    while(check() > 1 && Q > 1) Q >>= 1;
    string str = "\0";
    for(int i = 0; i < N; ++i){
      if(i != T)
        for(int j = 0, k = arr[i] / Q / 2; j < k; ++j) str.push_back(i + 'a');
    }
    for(int j = 0, k = arr[T] / Q; j < k; ++j) str.push_back(T + 'a');
    for(int i = N - 1; i >= 0; --i){
      if(i != T)
        for(int j = 0, k = arr[i] / Q / 2; j < k; ++j) str.push_back(i + 'a');
    }
    while(Q--) cout << str;
    printf("\n");
  }

}

int main(void){
  int i, j;

  ini();

  sol();

}
