import java.math.BigInteger;
import java.util.Scanner;                     //import for input
public class main{
  public static void main(String[] args){     //main
    Scanner input = new Scanner(System.in);   //get input
    int N;
    String str = "0";
    BigInteger A = new BigInteger( str ), B = new BigInteger( str );

    N = input.nextInt();
    for(int i = 0; i < N; ++i){
      str = input.nextLine();
      A = new BigInteger(str);
      str = input.nextLine();
      B = new BigInteger(str);
      System.out.println(A.multiply( B ));
    }
  }
}
