#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
char shif[10], str[105], arr[40] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
map<char, int> m;
void ini(void){
  scanf("%s%s", shif, str);
  N = (shif[0] == 'L')? 1: -1;
  m['q'] = 0;
  m['w'] = 1;
  m['e'] = 2;
  m['r'] = 3;
  m['t'] = 4;
  m['y'] = 5;
  m['u'] = 6;
  m['i'] = 7;
  m['o'] = 8;
  m['p'] = 9;
  m['a'] = 10;
  m['s'] = 11;
  m['d'] = 12;
  m['f'] = 13;
  m['g'] = 14;
  m['h'] = 15;
  m['j'] = 16;
  m['k'] = 17;
  m['l'] = 18;
  m[';'] = 19;
  m['z'] = 20;
  m['x'] = 21;
  m['c'] = 22;
  m['v'] = 23;
  m['b'] = 24;
  m['n'] = 25;
  m['m'] = 26;
  m[','] = 27;
  m['.'] = 28;
  m['/'] = 29;
}

void sol(void){
  for(int i = 0, j = strlen(str); i < j; ++i){
    if(m[str[i]] + N < 0) printf("%c", arr[28]);
    else if(m[str[i]] + N > 29) printf("%c", arr[0]); //這裡邊界改了之後忘記改
    else printf("%c", arr[m[str[i]] + N]);
  }
  printf("\n");
}

int main(void){
  int i, j;

  ini();

  sol();

}
