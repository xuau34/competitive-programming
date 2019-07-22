#include <bits/stdc++.h>
using namespace std;
int T, N, M, Q;
FILE *in, *out;
void ini(void){
  fscanf(in, "%d", &N);
}

void sol(void){
  fprintf(out, "%d\n", (N & 1) ^ 1);
}

int main(void){
  int i, j;
  in = fopen("input.txt", "r"), out = fopen("output.txt", "w+");
  fscanf(in, "%d", &T);
  while(T--){
    ini();
    sol();
  }
}
