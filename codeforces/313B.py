#from operator import attregetter #arr.sort(key = attrgetter(arr[i].?, arr[i].?, ...), reverse = True(or false))

def main():
  Case = 1
  
  while(Case):
    string = str( raw_input() )
    N = len( string )
    pre = [0] * (N + 10)
    for i in xrange(N - 1): 
      pre[i + 1] = pre[i]
      if(string[i] == string[i + 1]): pre[i + 1] += 1 
    M = int( raw_input() )
    while( M > 0 ):
      l, r = map(int, raw_input().split())
      print pre[r - 1] - pre[l - 1]
      M -= 1
    Case -= 1;

main()
