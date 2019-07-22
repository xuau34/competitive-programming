import java.math.BigInteger;
import java.util.Scanner;                     //import for input
public class Main{
  public static void main(String[] args){     //main
    Scanner input = new Scanner(System.in);   //get input
    int N;
    BigInteger[] f = new BigInteger[5005];
    f[0] = BigInteger.ZERO;
    f[1] = BigInteger.ONE;
    for(int i = 2; i < 5001; ++i) f[i] = f[i - 1].add( f[i - 2] );
    while( input.hasNext() ){
      N = input.nextInt();
      System.out.println("The Fibonacci number for " + N + " is " + f[N]); //get if retry
    }
  }
}
