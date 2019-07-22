#include <bits/stdc++.h>
using namespace std;

void ERROR(const string &s) {
  fprintf(stderr, "ERROR: %s\n", s.c_str());
  exit(1);
}

void WA(const string &s = "") {
  puts("WA");
  if (s != "") printf("%s\n", s.c_str());
  exit(0);
}

void AC(const string &s = "") {
  puts("AC");
  if (s != "") printf("%s\n", s.c_str());
  exit(0);
}

struct Checker {
  ifstream f_user_out;
  int T, n;
  char buf[64] = {};
  unsigned ala;

  void init(int argc, char **argv) {
    //if(argc <= 2) ERROR("USAGE: ./judge user_code user_out");
    f_user_out.open("in"); // only need <user_out>
  }

  int readint() {
    string s;
    getline(f_user_out, s);
    if(s.length() == 0 || s.length() > 10) WA("Too long.");
    if (!f_user_out.good()) WA("Not good.");
    int val = 0;
    for(auto c: s)
      if(c > '9' || c < '0') WA("Digits only.");
      else val = val * 10 + c - '0';
    return val;
  }
  void log(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf+strlen(buf), fmt, ap);
    va_end(ap);
  }
  void check() {
    T = readint();
    if(T != 1) WA("Invalid T.");
    log("OK: T=1\n");
    n = readint();
    log("OK: valid n\n");
    alalala();
    for(int i = 0; i < 70; i++) cout<<buf[i];
    cout<<endl<<ala<<endl;
    //cout<<strlen(buf)<<endl;
    if(ala == 0) WA("Nice try, but I'll never let you AC!"); // ^_^

    log("Checking if alalala(%d) equals 0...", n);
    cout<<endl;
    for(int i = 0; i < 70; i++) cout<<buf[i];
    cout<<endl<<ala<<endl<<endl;
    //cout<<strlen(buf)<<endl;
    if(ala) {
      log("You bad.");
      WA(buf);
    }
    else {
      log("<3");
      AC(buf);
    }
  }

  void alalala() {
    ala = 0;
    unsigned piv = 0xdeadbeef;  //3735928559
    for(int i = 0; i < 32; i++) {
      if(n & (1u << i)) ala ^= piv;
      ala <<= 1;
    }
  }
} checker;
int main(int argc, char *argv[]){
  checker.init(argc, argv);
  checker.check();
  return 0;
} 
