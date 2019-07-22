#from operator import attregetter #arr.sort(key = attrgetter(arr[i].?, arr[i].?, ...), reverse = True(or false))

def main():
  Case = 1
  
  while(Case):
    N = int( raw_input() )
    a = map(int, raw_input().split())
    M = int( raw_input() )
    b = map(int, raw_input().split())
    
    a.sort()
    b.sort()

    ans = 0
    i = 0
    j = 0
    while( i < N and j < M ):
      if( abs( a[i] - b[j] ) <= 1 ):
        ans += 1
        i += 1
        j += 1
      elif( a[i] < b[j] ): i += 1
      else: j += 1

    print ans


    Case -= 1;

main()
