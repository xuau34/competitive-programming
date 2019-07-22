#from operator import attregetter #arr.sort(key = attrgetter(arr[i].?, arr[i].?, ...), reverse = True(or false))
from __future__ import print_function

def main():
  Case = 1
  
  while(Case):
    Q = 0
    N, M = map(int, raw_input().split())
    if(M == 0 and N > 1):
      print( "-1 -1" )
      return
    arr = [0] * 10
    i = 9
    while(M > 0 and i > 0):
      arr[i] = M / i
      Q += arr[i]
      M %= i; i -= 1
    if(Q > N):
      print( "-1 -1" )
      return
    arr[0] = N - Q
    f = 0
    i = 0
    if(N > 1 and arr[0]):
      print( "1", end = '' )
      f = i = 1
    while(i < arr[0]):
      print( "%d" % 0, end = '' )
      i += 1
    i = 1
    while(i < 10):
      j = 0
      if(arr[i] and f):
        print( "%d" % (i - 1), end = '' )
        j = 1
        f = 0
      while(j < arr[i]):
        print( "%d" % i, end = '' )
        j += 1
      i += 1
    print( " ", end = '' )
    i = 9
    while(i >= 0):
      j = 0
      while(j < arr[i]):
        print( "%d" % i, end = '' )
        j += 1
      i -= 1
    print( "" )
    Case -= 1

main()
