import java.util.Scanner;
import java.math.BigDecimal;
import java.math.BigInteger;

public class Main{
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int N = 1000010;
        BigDecimal[] a;
        BigDecimal one = new BigDecimal(1);
        a[0] = new BigDecimal(0);
        for(int i = 1; i < N; i ++) {
            BigDecimal tmp = new BigDecimal(i);
            a[i] = a[i-1].add(one.divide(tmp.multiply(tmp)));
        }
        while(cin.hasNext()) {
            int n = cin.nextInt();
            System.out.println("a+b:"+a[n]);
        }
    }
}