import java.math.*;
import java.io.*;
import java.util.*;

public class MainJ{
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        while(n-- > 0){
            BigInteger b = BigInteger.ZERO;
            while(cin.hasNextBigInteger()){
                BigInteger c = cin.nextBigInteger();
                if(!c.equals(BigInteger.valueOf(0))){
                    b = b.add(c);
                }else{
                    System.out.println(b);
                    if(n != 0){
                        System.out.println();
                        break;
                    }
                }
            }
        }
    }
}
