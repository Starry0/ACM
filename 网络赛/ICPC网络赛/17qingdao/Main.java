import java.io.*;
import java.util.*;
import java.math.BigDecimal;
public class Main {
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        int n=cin.nextInt();
        while(n!=0) {
            n--;
            BigDecimal[] x=new BigDecimal[4];
            BigDecimal[] y=new BigDecimal[4];
            for(int i=0;i<4;i++) {
                x[i]=cin.nextBigDecimal();
                y[i]=cin.nextBigDecimal();
            }
            BigDecimal two=new BigDecimal(2);
            BigDecimal a1,a2,b1,b2,c1,c2;
            a1=two.multiply(x[1].subtract(x[0]));
            b1=two.multiply(y[1].subtract(y[0]));
            c1=x[1].multiply(x[1]).add(y[1].multiply(y[1])).subtract(x[0].multiply(x[0]).add(y[0].multiply(y[0])));
            a2=two.multiply(x[2].subtract(x[1]));
            b2=two.multiply(y[2].subtract(y[1]));
            c2=x[2].multiply(x[2]).add(y[2].multiply(y[2])).subtract(x[1].multiply(x[1]).add(y[1].multiply(y[1])));
            BigDecimal nx=(c1.multiply(b2).subtract(c2.multiply(b1))).divide(a1.multiply(b2).subtract(a2.multiply(b1)));
            BigDecimal ny=(a1.multiply(c2).subtract(a2.multiply(c1))).divide(a1.multiply(b2).subtract(a2.multiply(b1)));
            BigDecimal R=(nx.subtract(x[0]).multiply(nx.subtract(x[0]))).add(ny.subtract(y[0]).multiply(ny.subtract(y[0])));
            BigDecimal dd=(nx.subtract(x[3]).multiply(nx.subtract(x[3]))).add(ny.subtract(y[3]).multiply(ny.subtract(y[3])));
            long zero=0;
            if(dd.compareTo(R)==1)
            {
                System.out.println("Accepted");
            }
            else
            {
                System.out.println("Rejected");
            }
        }
    }
}