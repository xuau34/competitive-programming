from fractions import gcd

def main():
  T = int( raw_input() )
  for Case in xrange( T ):
    N, L = map(int, raw_input().split() )
    arr = map( int, raw_input().split() )

    ans = [0] * (L + 1)
    ans[1] = X = gcd( arr[0], arr[1] )

    if( X == 0 ):
        while( True ):
          continue
    
    ans[0] = arr[0] / X
    ans[2] = arr[1] / X

    for i in xrange( L - 2 ):
      ans[i + 3] = arr[i + 2] / ans[i + 2]

    primes = sorted( { i for i in ans } )
    MAP = { primes[i]: chr( ord('A') + i ) for i in xrange( len(primes) ) }

    print( "Case #%d: %s" % (Case + 1, ''.join( [ MAP[ i ] for i in ans])) )

if __name__ == '__main__':
  main()
