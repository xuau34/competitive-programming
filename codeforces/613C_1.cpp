#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[30],n;
int b[101000];
int gcd(int x,int y)
{return y?gcd(y,x%y):x;}
int main()
{
  cin >> n;
  int ans = 0,cnt = 0;
  for (int i = 1;i <= n;i++) cin >> a[i];
  for (int i = 1;i <= n;i++) ans = gcd(ans,a[i]);
  for (int i = 1;i <= n;i++) cnt += a[i]&1;
  if (cnt > 1)
  {
    cout << 0 << endl;
    for (int i = 1;i <= n;i++)
      for (int j = 1;j <= a[i];j++)
        printf("%c",'a'+i-1);
    printf("\n");
    return 0;
  }

  cnt = 0;
  for (int i = 1;i <= n;i++) a[i]/=ans,cnt+=a[i]&1;
  cout << ans << endl;
  if (cnt > 1) 
  {
    ans /=2;for (int i = 1;i <= n;i++) a[i]*=2;
  }
  int m = 0;
  for (int i = 1;i <= n;i++)
    for (int j = 1;j <= a[i];j++)
      m++;
  int l = 1,r = m;
  for (int i = 1;i <= n;i++)
    for (int j = 1;j <= a[i]/2;j++)
      b[l++]=i,b[r--]=i;
  for (int i = 1;i <= n;i++)
    if (a[i]&1) b[l++]=i;
  while (ans--)
    for (int i = 1;i <= m;i++)
      printf("%c",b[i]+'a'-1);
}
