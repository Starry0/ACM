import java.util.Scanner;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main{
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        p = cin.nextInt();
        while(p-- > 0) {
            BigDecimal k = cin.nextBigDecimal();
            BigDecimal b = cin.nextBigDecimal();
            BigInteger n = cin.nextBigInteger();
            System.out.println("a+b:"+a.add(b));
        }
        BigDecimal a = cin.nextBigDecimal();
        BigDecimal b = cin.nextBigDecimal();
        BigInteger aa = cin.nextBigInteger();
        BigInteger bb = cin.nextBigInteger();
        System.out.println("a+b:"+a.add(b));
        System.out.println("a-b:"+a.subtract(b));
        System.out.println("a*b:"+a.multiply(b));
        System.out.println("a/b:"+aa.divide(bb));
        System.out.println("a^10:"+a.pow(10));
    }
}