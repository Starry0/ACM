import java.math.*;
import java.io.*;
import java.util.*;

public class MainK{
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger[] f = new BigInteger[10000];
        f[1] = new BigInteger("1");
        f[2] = new BigInteger("2");
        for(int i = 3; i < 1000; i ++){
            f[i] = new BigInteger("0");
            f[i] = f[i].add(f[i-1]).add(f[i-2]);
        }
        //System.out.println(f[900]);
        while(cin.hasNextBigInteger()){
            BigInteger a = cin.nextBigInteger();
            BigInteger b = cin.nextBigInteger();
            if(a.equals(BigInteger.ZERO) && b.equals(BigInteger.ZERO))break;
            int ans = 0;
            for(int i = 1; i < 1000; i ++){
                if(a.compareTo(f[i]) <= 0 && b.compareTo(f[i]) >= 0){
                    ans ++;
                }
            }
            System.out.println(ans);
        }
    }
}
