import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		BigDecimal two = new BigDecimal(2);
		BigDecimal pi = new BigDecimal(Math.PI);
		while(t-- > 0) {
			BigDecimal a = cin.nextBigDecimal();
			BigDecimal b = cin.nextBigDecimal();
			BigDecimal c = a.multiply(b).multiply(pi).add(b.multiply(two).multiply(b));
			System.out.println(c);
		}
	}
}