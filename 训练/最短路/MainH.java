import java.math.*;
import java.io.*;
import java.util.*;
public class MainH{
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            BigDecimal ans = cin.nextBigDecimal();
            int n = cin.nextInt();
            String res = ans.pow(n).stripTrailingZeros().toPlainString();
            // res.startsWith(".");
            if(res.charAt(0)=='0') res=res.substring(1);
            System.out.println(res);
        }
    }
}
