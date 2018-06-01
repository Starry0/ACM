import java.math.*;
import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n;
        while(cin.hasNext()){
            n = cin.nextInt();
            BigInteger ans = BigInteger.ONE;
            for(int i = 1; i <= n; i ++){
                ans = ans.multiply(BigInteger.valueOf(i));
            }
            System.out.println(ans);
        }
    }
}
