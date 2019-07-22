#include <bits/stdc++.h>
using namespace std;
unsigned alalala(int n) {
  unsigned ala = 0;
  unsigned piv = 0xdeadbeef;  //3735928559
  for(int i = 0; i < 32; i++) {
    if(n & (1u << i)) ala ^= piv;
    ala <<= 1;
  }
  return ala;
}
int main(int argc, char *argv[]){
  //checker.init(argc, argv);
  //checker.check();
  /*
  while(1){
    int i;
    cin>>i;
    cout<<alalala(i)<<endl;
  }
  */
  for(int i = -2147483648; i <= -1000000000; i++){
    unsigned j = alalala(i);
    if(j > 0 && j <= 255) cout<<i<<endl; 
  }
  return 0;
} 
