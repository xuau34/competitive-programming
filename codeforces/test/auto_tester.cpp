//hi~ :)
#include <iostream>

#define judger                "./correct"
#define test                  "./wrong"
#define autoGen               "./generator"
#define judgerOutput          "out_correct"
#define testOutput            "out_wrong"
#define inputFile             "test_in"

#define maxTimes              5000

using namespace std;


int main(){
  int timer = 0;

  string gen = autoGen;
  gen += " > ", gen += inputFile;

  string out_AC = judger;
  out_AC += " < ", out_AC += inputFile, out_AC += " > ", out_AC += judgerOutput;

  string out_WA = test;
  out_WA += " < ", out_WA += inputFile, out_WA += " > ", out_WA += testOutput;

  string diff = "diff ";
  diff += judgerOutput, diff += " ", diff += testOutput;

  do{
    system(gen.c_str());        // 生測資
    system(out_AC.c_str());     // 跑答案
    system(out_WA.c_str());     // 跑output
    if(timer%50 == 49) cerr << ".";     // 進度條
    if(timer%500 == 499) cerr << endl;
  }while(!system(diff.c_str()) and timer++ < maxTimes);

  if(timer == maxTimes) puts("Accepted");
  else puts("Wrong Answer");

  return 0;
}
