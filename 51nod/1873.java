import java.util.Scanner;
import java.math.BigDecimal;

public class Main{
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigDecimal x;
		while(cin.hasNextBigDecimal()) {
			x = cin.nextBigDecimal();
			int n = cin.nextInt();
			x = x.pow(n);
			String s = x.stripTrailingZeros().toPlainString();
			if(s.charAt(0) == '0') {
				s = s.substring(1,s.length());
			}
			System.out.println(s);
		}
	}
}