/*
z_function:
i = 1 ~ n - 1, l = r = 0;
1. i <= r:  (i在已確認（算）過之區間)
z[i] = min(r - i + 1, z[l - i]);    //min速度不快
直接算出  此區間i~r的長度 or 前頭同s[i]的z值
2. (未確認之區間)
while(i + z[i] < n && s[z[i]] == s[i + z[i]])
這區間的位置不超過n   從頭到z[i]的長度的字 要同 從此i到z[i]的長度的字
z[i] += 1;

if(i + z[i] -1 > r)    //此區間之長度(i + z[i]) 的位置(-1) 若 大於前一區間之右界 更新 區間
l = i; r = i + z[i] - 1;
 */
#include <bits/stdc++.h>
#define NNN 1000000
using namespace std;
int z[NNN];
string str;
void Z(void){
  int i, l, r;
  for(z[0] = str.length(), i = 1, l = r = 0; i < z[0]; i++){
    if(i <= r) z[i] = (r - i + 1 < z[i- l])? (r - i + 1): (z[i - l]);
    else{
      while(i + z[i] < z[0] && str[z[i]] == str[i + z[i]]) z[i] += 1;
      if(i + z[i] - 1 > r){
        l = i;
        r = i + z[i] - 1;
      }
    }
  }
}
int main(void){
  cin>>str;
  memset(z, 0, sizeof(z));
  Z();
  for(int i = 0; i < z[0]; i++) printf("%d ", z[i]);
  cout<<endl;
}
